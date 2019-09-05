# Estimativa de Roll e Pitch para uma amostragem de acelerômetro

Basicamente, este projeto é composto por três módulos princípais, são eles: 

- <b>aplicação;</b>
- <b>logs;</b>
- <b>testes.</b>

A aplicação é formada pelos arquivos main.cpp, accelerometersample.cpp e accelerometersample.h. Resumidamente, enquanto primeiro arquivo é responsável pela leitura e escrita dos logs, os outros são responsáveis pelo cálculo dos ângulos Roll e Pitch e verificação das amostras.

Existem dois logs, um de entrada (attitude_exam.log) e outro de saída (roll_pitch.log). O log de entrada é consituído pela medições realizadas pelo acelerômetro e o log de saída pelos ângulos Roll e Picth, representados em graus. As amostras do log de entrada são lidas e utilizadas para cálculo dos ângulos, que são respectivamente escritos e salvos no log de saída no seguinte formato:

<p align="center"><b>
  (time_stamp_ms; roll; pitch)
</b></p>

Por fim, os testes verificam se as estimativas dos ângulos estão corretas para diversas amostras específicas. Ainda, com base no artigo (application-note), os testes também verificam se as amostras obedecem as restrições do modelo Roll e Pitch. Para facilitar a portabilidade do projeto, o framework Catch2 foi utilizado para os testes. Esse framework é composto apenas por um arquivo header e não necessita de instalação.

## Para executar

A execução da aplicação e dos testes é controlada pelo arquivo Makefile. Para executá-los é necessário estar no mesmo diretório deste arquivo. Além disso, é necessário ter o `make` instalado.

### Comandos para execução da Aplicação
- `make all`
- `./run`
- `make clean`

### Comandos para execução dos testes
- `make test`
- `./test`
- `make clean`
