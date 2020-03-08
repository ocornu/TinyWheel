#if DEVICE_TWRISTBAND == DEVICE_TWRISTBAND

#include <View.h>
#include <BoardUtils.h>
#include <TFT_eSPI.h>

#define VIEW_TWRISTBAND_ICON_HEIGHT 40
#define VIEW_TWRISTBAND_ICON_WIDTH  40

const unsigned char PROGMEM VIEW_TWRISTBAND_ICON_BMP_WHEEL[] = {
    // 'icon-wheel', 40x40px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00,
    0x0f, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00, 0xff,
    0xff, 0xff, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0x81, 0xff, 0xc0, 0x07, 0xfc, 0x00,
    0x3f, 0xe0, 0x07, 0xf8, 0x00, 0x1f, 0xf0, 0x0f, 0xf0, 0x3c, 0x0f, 0xf0, 0x1f, 0xe0, 0x3c, 0x07,
    0xf8, 0x1f, 0xc0, 0x3c, 0x03, 0xf8, 0x1f, 0x8e, 0x3c, 0x31, 0xf8, 0x3f, 0x8f, 0x7e, 0xf1, 0xfc,
    0x3f, 0x9f, 0xff, 0xf9, 0xfc, 0x3f, 0x0f, 0xff, 0xf0, 0xfc, 0x3f, 0x07, 0xff, 0xe0, 0xfc, 0x3f,
    0x01, 0xe7, 0x80, 0xfc, 0x3f, 0x01, 0xe7, 0x80, 0xfc, 0x3f, 0x07, 0xff, 0xe0, 0xfc, 0x3f, 0x0f,
    0xff, 0xf0, 0xfc, 0x3f, 0x9f, 0xff, 0xf9, 0xfc, 0x3f, 0x8f, 0x7e, 0xf1, 0xfc, 0x1f, 0x8e, 0x3c,
    0x71, 0xf8, 0x1f, 0xc0, 0x3c, 0x03, 0xf8, 0x1f, 0xe0, 0x3c, 0x07, 0xf8, 0x0f, 0xf0, 0x3c, 0x0f,
    0xf0, 0x0f, 0xf8, 0x00, 0x1f, 0xf0, 0x07, 0xfc, 0x00, 0x3f, 0xe0, 0x03, 0xff, 0x81, 0xff, 0xc0,
    0x01, 0xff, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x00,
    0x3f, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM VIEW_TWRISTBAND_ICON_BMP_CONNECTING[] = {
	// 'icon-connect', 40x40px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x00, 0x00, 0x1f,
    0xff, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff,
    0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0x00, 0xff, 0xf8, 0x1f, 0xf8, 0x00, 0x1f,
    0xf8, 0x0f, 0xe0, 0x00, 0x07, 0xf0, 0x07, 0x80, 0x00, 0x01, 0xe0, 0x03, 0x01, 0xff, 0x80, 0xc0,
    0x00, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x00,
    0x3f, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0x81, 0xf0, 0x00, 0x00, 0x06,
    0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c,
    0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM VIEW_TWRISTBAND_ICON_BMP_SPEED[] = {
    // 'icon-speed', 40x40px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x03, 0xe7, 0xe0, 0xe0, 0x00, 0x1f, 0xe7, 0xf9,
    0xc0, 0x00, 0x3f, 0xe7, 0xff, 0x80, 0x00, 0x7f, 0xe7, 0xff, 0x00, 0x00, 0x7f, 0xc7, 0xfe, 0x00,
    0x02, 0x30, 0x01, 0xfc, 0x40, 0x07, 0x00, 0x00, 0xf8, 0xe0, 0x0f, 0x80, 0x00, 0xf1, 0xf0, 0x1f,
    0x00, 0x01, 0xf3, 0xf8, 0x1e, 0x00, 0x03, 0xe7, 0xf8, 0x3c, 0x00, 0x0f, 0xc7, 0xfc, 0x38, 0x00,
    0x1f, 0x83, 0xfc, 0x78, 0x00, 0x3f, 0x01, 0xfe, 0x70, 0x00, 0x7e, 0x01, 0xfe, 0x70, 0x00, 0xfc,
    0x01, 0xfe, 0xf0, 0x01, 0xf8, 0x00, 0xff, 0xe0, 0x03, 0x30, 0x00, 0xff, 0xe0, 0x03, 0x30, 0x00,
    0xff, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char PROGMEM VIEW_TWRISTBAND_ICON_BMP_BATTERY[] = {
    // 'icon-battery', 40x40px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff,
    0xff, 0xc0, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff,
    0xe0, 0x7f, 0xff, 0xff, 0xff, 0xec, 0x7f, 0xff, 0xff, 0xff, 0xec, 0x7f, 0x7f, 0xff, 0xff, 0xee,
    0x7f, 0x8f, 0x9f, 0xff, 0xee, 0x7f, 0xe3, 0x87, 0xff, 0xee, 0x7f, 0xf0, 0x81, 0xff, 0xee, 0x7f,
    0xfc, 0x00, 0x7f, 0xee, 0x7f, 0xfe, 0x00, 0x1f, 0xee, 0x7f, 0xff, 0x00, 0x07, 0xee, 0x7f, 0xff,
    0xc4, 0x03, 0xee, 0x7f, 0xff, 0xe7, 0x03, 0xee, 0x7f, 0xff, 0xf7, 0xc3, 0xee, 0x7f, 0xff, 0xff,
    0xf3, 0xee, 0x7f, 0xff, 0xff, 0xff, 0xec, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff,
    0xe0, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 0xff, 0xc0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void drawSpeedValue(TFT_eSPI* display, uint8_t speed) {
    char buffer[2];

    sprintf(buffer, "%02d", speed);

    display->setTextColor(TFT_GREEN, TFT_BLACK);
    display->setTextSize(7);

    display->drawChar(
        buffer[0],
        2 + (TFT_WIDTH - VIEW_TWRISTBAND_ICON_WIDTH) / 2,
        VIEW_TWRISTBAND_ICON_HEIGHT
    );

    display->drawChar(
        buffer[1],
        2 + (TFT_WIDTH - VIEW_TWRISTBAND_ICON_WIDTH) / 2,
        VIEW_TWRISTBAND_ICON_HEIGHT + 60
    );
};

void drawBatteryValue(TFT_eSPI* display, uint8_t percentage) {
    char buffer[4];

    sprintf(buffer, "%u%%", percentage);

    // log_i("buffer : %s", buffer);

    const uint8_t x = 20;
    const uint8_t y = VIEW_TWRISTBAND_ICON_HEIGHT + 10;
    const uint8_t w = 40;
    const uint8_t h = 80;

    const uint8_t margin = 2;
    const uint8_t barWidth = w - 2 * margin;
    const uint8_t barHeight = h - 2 * margin;
    const uint8_t barFill = barHeight - (barHeight * percentage / 100.0);

    uint32_t color = TFT_GREEN;

    if (percentage < 25) {
        color = TFT_YELLOW;
    }

    if (percentage < 15) {
        color = TFT_RED;
    }

    display->fillRect(
        0,
        y,
        TFT_WIDTH,
        TFT_HEIGHT - y,
        TFT_BLACK
    );

    display->drawRoundRect(x, y, w, h, 3, TFT_GOLD);

    if (percentage == 0) {
        return;
    }

    display->fillRect(
        x + margin,
        (y + margin) + barFill,
        barWidth,
        barHeight - barFill,
        color
    );

    display->setTextSize(2);
    display->setTextDatum(TC_DATUM);
    display->setTextColor(TFT_CYAN, TFT_BLACK);
    display->drawString(String(buffer), TFT_WIDTH / 2, TFT_HEIGHT - 10);
};

void drawIcon(TFT_eSPI* display, const uint8_t *bitmap) {
    display->drawBitmap(
        (TFT_WIDTH / 2) - (VIEW_TWRISTBAND_ICON_WIDTH / 2),
        0,
        bitmap,
        VIEW_TWRISTBAND_ICON_WIDTH,
        VIEW_TWRISTBAND_ICON_HEIGHT,
        TFT_WHITE
    );
};

void drawVerticalText(TFT_eSPI* display, std::string text, int32_t x, int32_t y, int32_t spaces = 20) {
    for (size_t i = 0; i < text.length(); i++) {
        display->drawChar(text.at(i), x, y + (spaces * i));
    }
};

template <> bool ViewPageSpeed<TFT_eSPI>::draw(TFT_eSPI* display) {
    display->fillScreen(TFT_BLACK);

    drawIcon(display, VIEW_TWRISTBAND_ICON_BMP_SPEED);

    drawSpeedValue(display, 0);

    return true;
};

template <> bool ViewPageSpeed<TFT_eSPI>::update(TFT_eSPI* display, Wheel::Values* values) {
    WheelValue* value = values->get(WHEEL_CHARACTERISTIC_SPEED_RPM_UUID);
    uint8_t speed = value->format(&WheelValue::FORMATTER_KILOMETERS_PER_HOUR);

    log_d("speed : %u", speed);

    drawSpeedValue(display, speed);

    return true;
};

template <> bool ViewPageBattery<TFT_eSPI>::draw(TFT_eSPI* display) {
    display->fillScreen(TFT_BLACK);

    drawIcon(display, VIEW_TWRISTBAND_ICON_BMP_BATTERY);

    drawBatteryValue(display, 0);

    return true;
};

template <> bool ViewPageBattery<TFT_eSPI>::update(TFT_eSPI* display, Wheel::Values* values) {
    WheelValue* value = values->get(WHEEL_CHARACTERISTIC_BATTERY_REMAINING_UUID);
    uint8_t percentage = value->format(&WheelValue::FORMATTER_BATTERY_REMAINING);

    log_d("percentage : %u", percentage);

    drawBatteryValue(display, percentage);

    return true;
};

template <> bool ViewPageConnecting<TFT_eSPI>::draw(TFT_eSPI* display) {
    display->fillScreen(TFT_BLACK);

    drawIcon(display, VIEW_TWRISTBAND_ICON_BMP_CONNECTING);

    const uint8_t dots = 5;
    const uint8_t space = 15;
    const uint8_t radius = 5;
    const uint8_t interval = 5;
    const uint16_t x = VIEW_TWRISTBAND_ICON_WIDTH;
    const uint16_t y = VIEW_TWRISTBAND_ICON_HEIGHT;
    const uint8_t bucket = 1 + (millis() / 1000 / interval) % dots;

    display->setTextSize(1);
    display->setTextDatum(TC_DATUM);
    display->setTextColor(TFT_CYAN, TFT_BLACK);
    display->drawString("Connecting", TFT_WIDTH / 2, TFT_HEIGHT - 20);

    for (uint8_t i = 1; i <= dots; i++) {
        display->fillCircle(
            x,
            y + (space * i),
            radius,
            (bucket == i) ? TFT_RED : TFT_YELLOW
        );
    }

    return true;
};

template <> bool ViewPageHome<TFT_eSPI>::draw(TFT_eSPI* display) {
    // draw it every ~10s
    if (this->lastChange > 0 && millis() - this->lastChange < 10000) {
        return false;
    }

    display->fillScreen(TFT_BLACK);

    drawIcon(display, VIEW_TWRISTBAND_ICON_BMP_WHEEL);

    display->setTextSize(2);
    display->setTextColor(TFT_CYAN, TFT_BLACK);

    drawVerticalText(
        display,
        "Tiny",
        4 + (TFT_WIDTH - VIEW_TWRISTBAND_ICON_WIDTH) / 2,
        10 + VIEW_TWRISTBAND_ICON_HEIGHT
    );

    drawVerticalText(
        display,
        "Wheel",
        30 + (TFT_WIDTH - VIEW_TWRISTBAND_ICON_WIDTH) / 2,
        10 + VIEW_TWRISTBAND_ICON_HEIGHT
    );

    const uint8_t voltagePerc = BoardUtils::getBatteryPercentage();
    const uint8_t voltageW = 30;
    const uint8_t voltageH = 20;

    uint32_t voltageColor = TFT_GREEN;

    const uint8_t voltageX = 5;
    const uint8_t voltageY = TFT_HEIGHT - 20;

    const uint8_t voltageMargin = 2;
    const uint8_t voltageBarWidth = voltageW - 2 * voltageMargin;
    const uint8_t voltageBarHeight = voltageH - 2 * voltageMargin;

    log_d("Board Percentage : %u", voltagePerc);

    if (voltagePerc < 30) {
        voltageColor = TFT_YELLOW;
    }

    if (voltagePerc < 15) {
        voltageColor = TFT_RED;
    }

    display->fillRect(
        0,
        voltageY,
        voltageW,
        voltageH,
        TFT_BLACK
    );

    display->drawRoundRect(
        voltageX,
        voltageY,
        voltageW,
        voltageH,
        3,
        TFT_GOLD
    );

    display->fillRect(
        voltageX + voltageMargin,
        voltageY + voltageMargin,
        voltageBarWidth * voltagePerc / 100.0,
        voltageBarHeight,
        voltageColor
    );

    return true;
};

template <> bool ViewPageSleep<TFT_eSPI>::draw(TFT_eSPI* display) {
    for (uint8_t i = 0; i < 3; i++) {
        uint8_t n = 100;

        display->fillScreen(TFT_BLACK);

        while (n--)
        {
            display->drawPixel(
                random(TFT_WIDTH),
                random(TFT_HEIGHT),
                random(0x10000)
            );
        }

        delay(200);
    }

    display->fillScreen(TFT_BLACK);

    return true;
};

#endif