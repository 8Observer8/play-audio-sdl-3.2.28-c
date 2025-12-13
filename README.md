**Newer version (uses pre-release SDL 3.3.4):**
https://github.com/8Observer8/play-audio-sdl3-3.3.4-c

# Play Audio SDL3 (C)

**Demo in the browser:** https://8observer8.github.io/examples/sdl3/play-audio-sdl-3.2.28-c/

**EXE for Windows 10, 64-bit:** [play-audio-sdl-3.2.28-c-exe.zip](https://www.dropbox.com/scl/fi/0qtdgo6zs478r7532ukxm/play-audio-sdl-3-2-28-c-exe.zip?rlkey=v62lx7qiuhsad68ripdgvqs6n&st=s2jm6upj&raw=1)
- Zip size: 1.99 MB
- Unzipped: 4.45 MB

---

## File Sizes

**WASM ( built with Emscripten 4.0.15):**

- `index.html` — 869 bytes
- `app.js` — 178 KB
- `app.wasm` — 1.64 MB
- **Total:** 1.82 MB

**EXE (built with MinGW GCC 11.2):**

- EXE — 49.2 KB
- `SDL3.dll` (v3.2.28) — 2.4 MB
- `SDL3_mixer.dll`(v3.0.0) — 1.57 MB
- Assets ([picked-coin-echo-2.wav](https://opengameart.org/content/picked-coin-echo-2)) — 444 KB
- **Total:** 4.45 MB

---

## Tools to Build the EXE

- [MinGW GCC 11.2](https://github.com/brechtsanders/winlibs_mingw/releases/download/11.2.0-14.0.0-9.0.0-ucrt-r7/winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64ucrt-9.0.0-r7.zip) (zip - 178 MB, unzipped - 671 MB)
- [SDL3-3.2.28-win32-x64.zip](https://www.dropbox.com/scl/fi/f43wal3dw54e8erw56prj/SDL3-3.2.28-win32-x64.zip?rlkey=s973q3ci0lvwvt4yrg6nklu38&st=hwoanaix&raw=1) (zip - 0.98 MB, unzipped - 2.4 MB)
- [SDL3-devel-3.2.28-mingw.zip](https://www.dropbox.com/scl/fi/z9sfnlbyph1h3rv83acy0/SDL3-devel-3.2.28-mingw.zip?rlkey=58noqvn8xhu1ypjetv9984fn8&st=5cdlvayf&raw=1) (zip - 2.35 MB, unzipped - 8.55 MB)
- [SDL3_mixer-3.0.0-win32-x64.zip](https://www.dropbox.com/scl/fi/nwf39yszg03aws8lo4au4/SDL3_mixer-3.0.0-win32-x64.zip?rlkey=77t92h7jjlmr6ql2cxaaw6dxd&st=12fb4kli&raw=1) (zip - 668 KB, unzipped - 1.57 MB)
- [SDL3_mixer-devel-3.0.0-mingw.zip](https://www.dropbox.com/scl/fi/n0vtphup4qfxl59poyz10/SDL3_mixer-devel-3.0.0-mingw.zip?rlkey=zuuan7wj50y5evx7pw7oyeezg&st=57vaeoa5&raw=1) (zip - 712 KB, unzipped - 1.75 MB)

---

## Tools to Build WebAssembly

- [Emscripten 4.0.15](https://emscripten.org/docs/getting_started/downloads.html) (1.82 GB)
- [SDL3-devel-3.2.28-wasm.zip](https://www.dropbox.com/scl/fi/qhy3ngt1iwf3hbohu0ktw/SDL3-devel-3.2.28-wasm.zip?rlkey=rel1nm8o1i8qouqu4ld0au0xp&st=bongrnvb&raw=1) (zip - 1.16 MB, unzipped - 5 MB)
- [SDL3_mixer-devel-3.0.0-wasm.zip](https://www.dropbox.com/scl/fi/xlrsbemomhe8u28ks2qft/SDL3_mixer-devel-3.0.0-wasm.zip?rlkey=t01glwcrublchsazzmlmxwgxn&st=6pjfo9xr&raw=1) (zip - 567 KB, unzipped - 1.14 MB)

---

## How to Build EXE (Windows)

- Add [MinGW GCC 11.2](https://github.com/brechtsanders/winlibs_mingw/releases/download/11.2.0-14.0.0-9.0.0-ucrt-r7/winlibs-x86_64-posix-seh-gcc-11.2.0-mingw-w64ucrt-9.0.0-r7.zip) `bin` folder to your `PATH`.
- Add [SDL3-3.2.28-win32-x64.zip](https://www.dropbox.com/scl/fi/f43wal3dw54e8erw56prj/SDL3-3.2.28-win32-x64.zip?rlkey=s973q3ci0lvwvt4yrg6nklu38&st=eq7f1kcq&raw=1) folder to your `PATH`.
- Add [SDL3_mixer-3.0.0-win32-x64.zip](https://www.dropbox.com/scl/fi/nwf39yszg03aws8lo4au4/SDL3_mixer-3.0.0-win32-x64.zip?rlkey=77t92h7jjlmr6ql2cxaaw6dxd&st=6iamayq0&raw=1) folder to your `PATH`.
- Configure paths in `config-web.bat` for your SDL3 libraries.
- From the project root, run:

```bat
config-exe
build-exe
run-exe
```

## How to Build WebAssembly

1. Set up [Emscripten 4.0.15](https://emscripten.org/docs/getting_started/downloads.html) and Node.js
2. Install http-server globally:

```bat
npm i http-server -g
```

3. Configure paths in `config-web.bat` for your SDL3 libraries.
4. From the project root, run:

```bat
config-web
build-web
http-server -c-1
```

5. Open your browser and go to http://localhost:8080 to run the app locally.

> Note: You can also run the WASM app on Android via Wi-Fi using http-server. After starting the server, it will show local URL addresses — just type one into your mobile browser.
