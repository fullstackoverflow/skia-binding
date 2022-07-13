# skia-binding

## Build

### skia
```
cd skia
bin/gn gen ../build --args='is_debug=false is_official_build=true skia_use_system_expat=false skia_use_system_icu=false skia_use_system_libjpeg_turbo=false skia_use_system_libpng=false skia_use_system_libwebp=false skia_use_system_zlib=false skia_use_sfntly=false skia_use_freetype=true skia_use_harfbuzz=true skia_pdf_subset_harfbuzz=true skia_use_fontconfig=false skia_use_system_freetype2=false skia_use_system_harfbuzz=false'
ninja -C ../build/ skia modules
```

### exmaple
```
cd src/exmaple
clang++ -std=c++17 HelloWorld.cpp -L../../build -lskia -lGL -lfreetype -lpthread -I/root/skia-binding/skia/ -o main
```