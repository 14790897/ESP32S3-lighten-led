#include <Arduino.h>
#include <FastLED.h>

// WS2812 LED配置
#define LED_PIN     48      // WS2812 数据引脚，根据你的开发板修改
#define NUM_LEDS    1       // LED数量，板载通常是1个
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS  50      // 亮度 0-255

CRGB leds[NUM_LEDS];

// 彩虹效果参数
uint8_t gHue = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("WS2812 控制示例启动");
  
  // 初始化FastLED
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  
  Serial.println("WS2812 初始化完成");
}

void loop() {
  // 示例1: 静态颜色循环
  static unsigned long lastChange = 0;
  static uint8_t colorIndex = 0;
  
  if (millis() - lastChange > 2000) {  // 每2秒切换颜色
    lastChange = millis();
    
    switch(colorIndex) {
      case 0:
        leds[0] = CRGB::Red;
        Serial.println("红色");
        break;
      case 1:
        leds[0] = CRGB::Green;
        Serial.println("绿色");
        break;
      case 2:
        leds[0] = CRGB::Blue;
        Serial.println("蓝色");
        break;
      case 3:
        leds[0] = CRGB::Yellow;
        Serial.println("黄色");
        break;
      case 4:
        leds[0] = CRGB::Purple;
        Serial.println("紫色");
        break;
      case 5:
        leds[0] = CRGB::Cyan;
        Serial.println("青色");
        break;
    }
    
    colorIndex = (colorIndex + 1) % 6;
  }
  
  // 示例2: 彩虹效果（取消注释下面代码使用）
  /*
  leds[0] = CHSV(gHue, 255, 255);
  gHue++;
  */
  
  // 示例3: 呼吸灯效果（取消注释下面代码使用）
  /*
  static uint8_t brightness = 0;
  static int8_t direction = 1;
  
  brightness += direction;
  if (brightness == 0 || brightness == 255) {
    direction = -direction;
  }
  
  leds[0] = CRGB::Blue;
  FastLED.setBrightness(brightness);
  delay(10);
  */
  
  FastLED.show();
  delay(20);
}