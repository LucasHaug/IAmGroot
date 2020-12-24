# I Am Groot

Projeto embracado utilizando microcontrolador da família STM32 para falar num auto falante "I am Groot".

## Requisitos

* [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
  > É necessário colocar o local de instalação na varíavel de ambiente `CUBE_PATH`

* make
  > Linux: `sudo apt install make`
  >
  > Windows: `msys2> pacman -S make`

* [GNU Arm Embedded Toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads)
  > É necessário que a pasta `bin` dessa instalação esteja no `PATH`
  > e numa variável de ambiente `ARM_GCC_PATH`

* uncrustify
  > Linux: `sudo apt install uncrustify`
  >
  > Windows: Baixe o .zip no [SourceForge](https://sourceforge.net/projects/uncrustify/files/). Adicione o local do executável na variável de ambiente `PATH`.

* [Visual Studio Code](https://code.visualstudio.com/)
  * [EditorConfig](https://marketplace.visualstudio.com/items?itemName=EditorConfig.EditorConfig)
  * [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
  * [Cortex-Debug](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)

* [STM32 Cube Programmer](https://www.st.com/en/development-tools/stm32cubeprog.html) ou [J-Link](https://www.segger.com/downloads/jlink/)
  > É necessário que o executável também esteja no `PATH`

## Gerando arquivos

Com o arquivo do projeto na pasta correta, os seguintes comandos devem ser 
executados (necessário apenas após dar checkout no repositório ou mudar o cube):

```bash
make cube     # Gera arquivos do cube
make prepare  # Apaga os arquivos do cube desnecessários e gera arquivos de configuração do VS Code
```

Se, após modificar os arquivos do cube, ocorrer algum erro nos comandos acima,
pode rodar `make clean_cube` para apagar os arquivos gerados e então tentar 
novamente para que eles sejam gerados do zero.

## Compilando

Para compilar os arquivos rode

```bash
make
```

Às vezes, é necessário limpar os arquivos já compilados, se algum erro estiver 
acontecendo, para isso faça:

```bash
make clean
```

Isso apaga todos os arquivos de compilação gerados, exceto aqueles gerados a partir 
das bibliotecas da ST geradas pelo Cube, isso ocorre para agilizar um novo build,
já que raramente será necessário recompilar esses arquivos, mas caso seja necessário,
é possível limpar todos os arquivos de compilação com

```bash
make clean_all
```

## Gravando

Para gravar os arquivos na placa, rode

```bash
make flash
```

Ou, caso use um gravador com J-Link:

```bash
make jflash
```

## Links úteis

* https://www.st.com/resource/en/application_note/cd00259245-audio-and-waveform-generation-using-the-dac-in-stm32-products-stmicroelectronics.pdf
* https://os.mbed.com/users/4180_1/notebook/using-a-speaker-for-audio-output/
* https://www.instructables.com/Simple-Wav-Player-Using-Arduino/
* https://www.instructables.com/Play-SongsMP3-With-Arduino-Using-PWM-on-Speaker-or/

---

Estrutura de pastas, Makefile e configurações baseadas em: https://github.com/ThundeRatz/STM32ProjectTemplate
