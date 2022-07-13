#include "include/core/SkBitmap.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "include/core/SkData.h"
#include "include/core/SkImage.h"
#include "include/core/SkImageEncoder.h"
#include "include/core/SkPath.h"
#include "include/core/SkStream.h"
#include "include/core/SkString.h"
#include <chrono>
#include <iostream>

int main() {
    SkBitmap bmp;
    bmp.allocN32Pixels(500, 500);
    bmp.eraseColor(SK_ColorWHITE);
    SkCanvas canvas(bmp);

    canvas.drawColor(SK_ColorWHITE);

    SkPaint paint;
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(8);
    paint.setColor(0xff4285F4);
    paint.setAntiAlias(true);
    paint.setStrokeCap(SkPaint::kRound_Cap);

    SkPath path;
    path.moveTo(10, 10);
    path.quadTo(256, 64, 128, 128);
    path.quadTo(10, 192, 250, 250);
    canvas.drawPath(path, paint);
    auto image = SkImage::MakeFromEncoded(
        SkData::MakeFromFileName("/root/skia-binding/src/exmaple/logo.png"));
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        canvas.drawImage(image, 0, 0);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto cost =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count() * 1000;
    std::cout << "Cost:" << cost << std::endl;
    SkFILEWStream output("./output.png");
    SkEncodeImage(&output, bmp, SkEncodedImageFormat::kPNG, 100);
}