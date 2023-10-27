# Executando o Software de Métodos Numéricos

Este arquivo fornece instruções sobre como compilar e executar o código C++ que implementa métodos numéricos, incluindo o Método da Secante, o Método de Newton-Raphson e o Método de Newton Modificado.

## Pré-requisitos

Antes de executar o código, você precisa do seguinte:

1. **Compilador C++**: Você deve ter um compilador C++ instalado no seu sistema. O código está escrito em C++ e precisa de um compilador para ser construído e executado.

2. **Parâmetros de Entrada**: Você precisará fornecer parâmetros de entrada ao executar o código. Isso inclui o parâmetro de ajuste 'a' da função, a tolerância 'e' e opcionalmente a flag '-verbose' para habilitar a saída detalhada.

## Compilando o Código

1. Abra um terminal ou prompt de comando.

2. Navegue até o diretório onde o código está localizado.

3. Compile o código usando o comando `make`:

   ```bash
   make
   ```

Isso irá compilar o código e gerar um executável que você pode rodar.

## Executando o Programa

Após compilar com sucesso o código, você pode executar o programa com o seguinte comando:

```bash
./main <a> <tolerância> [-verbose]
```

- `<a>`: Um número de ponto flutuante representando o parâmetro de ajuste para os métodos.
- `<tolerância>`: Um número de ponto flutuante positivo representando a tolerância para os métodos.
- `[-verbose]` (opcional): Use esta flag para habilitar uma saída detalhada. Isso fornecerá informações adicionais sobre a execução de cada método. O arquivo CSV será gerado independentemente da flag `-verbose` estar ativa ou não.

Se você deseja executar um único caso de teste, você pode usar o seguinte comando:

```bash
./main <a> <tolerância> [-verbose]
```

Se você deseja executar vários casos de teste em um modo de lote, você pode usar o seguinte comando:

```bash
./main [-verbose]
```

O programa irá pedir que você insira o número de casos de teste e os valores 'a' e 'e' correspondentes para cada caso de teste.

## Saída

O programa gerará arquivos CSV para cada método, contendo os resultados dos cálculos. Esses arquivos serão nomeados com base no método e nos parâmetros de entrada.

Por exemplo, se você executar o programa e inserir `a = 1.0` e `e = 0.001`, ele gerará arquivos CSV como:

- `metodo_secante_a=1.000000_e=0.001000.csv`
- `newton_raphson_a=1.000000_e=0.001000.csv`
- `newton_modificado_a=1.000000_e=0.001000.csv`

Você pode analisar esses arquivos CSV para revisar os resultados dos métodos numéricos.