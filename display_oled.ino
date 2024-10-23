#include <Wire.h> //Biblioteca para uso do protocolo I2C;
#include <Adafruit_GFX.h> //Biblioteca para manipulação gráfica no display;
#include <Adafruit_SH1106.h> //Biblioteca para operação do driver de controle do display;

#include <Fonts/FreeMono9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeSansBoldOblique9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeMonoOblique9pt7b.h> //Fonte para alteração do texto;

#define OLED_RESET -1 //Em displays que não possuem pino RESET, é dado o valor -1;

Adafruit_SH1106 display(OLED_RESET); //Declaração da tela com o nome "display";

void setup() {
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); //Inicialização do display com a biblioteca e endereço de hardware do display;
}

void loop() {

  display.clearDisplay(); //Comando para limpar a tela;
  display.setFont(&FreeMonoOblique9pt7b); //Comando para definir a fonte que será utilizada;
  display.setTextColor(WHITE); //Comando para definir a cor do texto;
  display.setTextSize(1); //Comando para definir tamanho od
  display.setCursor(10, 22); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
  display.print("Calculator"); //Texto a ser escrito;

  display.setFont(&FreeMono9pt7b);
  display.setCursor(13, 47);
  display.print("9 + 9 x 9");

  display.display(); //Mostrar informações na tela;


  delay(3000);

  display.clearDisplay(); //Comando para limpar a tela;

  display.setCursor(0, 20); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
  display.print("90, acertou!"); //Texto a ser escrito;

  display.setCursor(5, 50); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
  display.print("162, errou!"); //Texto a ser escrito;
  
  display.display(); //Mostrar informações na tela;
  delay(3000);
  display.clearDisplay(); //Comando para limpar a tela;

  display.fillTriangle(90, 40, 105, 22, 120, 40, WHITE); //Desenhar triângulo preenchido (pos x1, pos y1, pos x2, pos y2, pos x3, pos y3, cor);
  display.display(); //Mostrar informações na tela;
  delay(3000);
}
