#define SDL_MAIN_USE_CALLBACKS 1 // Use the callbacks instead of main()
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_mixer/SDL_mixer.h>

// We will use this renderer to draw into this window every frame
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static Mix_Chunk *g_wave = NULL;

// This function runs once at startup
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    const char *title = "Play audio by click in C and SDL3";
    if (!SDL_CreateWindowAndRenderer(title, 350, 350, 0, &window, &renderer))
    {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // --- Print SDL versions ---
    SDL_Log("Compiled SDL3 version: %d.%d.%d",
        SDL_MAJOR_VERSION,
        SDL_MINOR_VERSION,
        SDL_MICRO_VERSION);
    // Get the version of the SDL library linked at runtime
    int v = SDL_GetVersion();
    SDL_Log("Linked SDL3 version:   %d.%d.%d", SDL_VERSIONNUM_MAJOR(v),
        SDL_VERSIONNUM_MINOR(v), SDL_VERSIONNUM_MICRO(v));

    // --- SDL3_mixer version ---
    v = Mix_Version();
    int major = SDL_VERSIONNUM_MAJOR(v);
    int minor = SDL_VERSIONNUM_MINOR(v);
    int micro = SDL_VERSIONNUM_MICRO(v);
    SDL_Log("SDL3_mixer version:    %d.%d.%d", major, minor, micro);

    SDL_AudioSpec spec;
    spec.freq = MIX_DEFAULT_FREQUENCY;
    spec.format = MIX_DEFAULT_FORMAT;
    spec.channels = MIX_DEFAULT_CHANNELS;

    // Open the audio device
    if (!Mix_OpenAudio(0, &spec))
    {
        SDL_Log("Couldn't open audio: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Load the WAV file
    const char *soundFilePath = "./assets/audio/picked-coin-echo-2.wav";
    g_wave = Mix_LoadWAV(soundFilePath);
    if (g_wave == NULL)
    {
        SDL_Log("Couldn't load WAV file %s: %s", soundFilePath, SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

// This function runs when a new event (mouse input, keypresses, etc) occurs
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS; // End the program, reporting success to the OS
    }
    else if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN)
    {
        // Play the sound effect
        Mix_PlayChannel(-1, g_wave, 0);
    }
    return SDL_APP_CONTINUE;
}

// This function runs once per frame, and is the heart of the program
SDL_AppResult SDL_AppIterate(void *appstate)
{
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Update the screen
    SDL_RenderPresent(renderer);
    return SDL_APP_CONTINUE;
}

// This function runs once at shutdown
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }

    if (window)
    {
        SDL_DestroyWindow(window);
        window = NULL;
    }

    if (g_wave)
    {
        Mix_FreeChunk(g_wave);
        g_wave = NULL;
    }

    SDL_Quit();
}
