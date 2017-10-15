#define LED_PIN 2
#define BUZZER_PIN 3
#define X_ACCEL_PIN 14
#define Y_ACCEL_PIN 15
#define Z_ACCEL_PIN 16

// Used for I2C on altimeter
#define SDA 18
#define SCL 19

#define SPI_SS 10 // CS on reader
#define SPI_SCK 13 //CLK on reader
#define SPI_MOSI 11 //DI on reader
#define SPI_MISO 12 // DO on reader

void init_pins(void);
