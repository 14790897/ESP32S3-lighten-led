# ESP32S3-lighten-led

一个用于演示在 ESP32-S3 开发板上控制单个 WS2812（NeoPixel）LED 的示例工程，基于 PlatformIO + Arduino 框架和 FastLED 库。

## 功能

- 演示静态颜色循环（红/绿/蓝/黄/紫/青）。
- 可选：彩虹颜色循环（CHSV）和呼吸灯效果（调整亮度）。

## 硬件

- **板载 WS2812B LED**（1个），数据引脚为 **GPIO 48**。
- 无需额外接线，开发板已集成 LED 和电源。

> 如需使用外接 WS2812 LED 灯带，请修改 `LED_PIN` 并连接：数据线 -> GPIO、VCC -> 5V/3.3V、GND -> GND。

## 依赖

- PlatformIO
- FastLED 库（项目中通过 PlatformIO 管理）

## 快速开始（使用 PlatformIO）

1. 打开项目目录（包含 `platformio.ini`）到 VS Code + PlatformIO 插件。
2. 编辑 `platformio.ini` 以选择或确认你的 ESP32-S3 开发板板型。
3. 连接开发板并点击“上传”（Upload）或运行：

   pio run -t upload

4. 在串口监视器查看输出（波特率 115200）：

   pio device monitor -b 115200

## 在代码中启用示例效果

- 静态颜色循环（默认启用）位于 `src/main.cpp` 的示例1。

- 要启用彩虹效果（示例2），取消注释：

  ```cpp
  leds[0] = CHSV(gHue, 255, 255);
  gHue++;
  ```

- 要启用呼吸灯效果（示例3），取消注释对应代码块并按需调整亮度与延时。

## 文件说明

- `src/main.cpp`：主程序示例代码。
- `platformio.ini`：PlatformIO 构建配置。

## 后续改进建议

- 将 `platformio.ini` 补充常见 ESP32-S3 板型示例。
- 添加更多 LED 效果示例并提供开关（菜单/串口命令）。

---
