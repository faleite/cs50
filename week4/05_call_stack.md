# Call Stack
### Pilha de chamadas
- Quando você chama uma função, o sistema reserva espaço na memória para que\
essa função faça o trabalho necessário.
    - Frequentemente chamamos esses blocos de quadros de **pilha de memória**\
    (stack frames) ou **quadros de função** (function frames).
- Mais de um quadro de pilha de uma função pode existir na memória em um\
determinado momento. Se main() chama move(), que então chama direction(), todas\
as três funções têm quadros abertos.
___

- Esses quadros são organizados em uma **pilha**. O quadro para a função\
chamada mais recentemente está sempre no topo da pilha.
- Quando uma nova função é chamada, um novo quadro é **colocado** no topo da\
pilha e se torna o quadro ativo.
- Quando uma função termina seu trabalho, seu quadro é **removido** da pilha e\
o quadro imediatamente abaixo dele torna-se a nova função ativa no topo da\
pilha. Esta função começa imediatamente de onde parou.

*Exemplo de call stack com a Função Fatorial:*
- Dentro deste código temos duas funções
- Onde temos a função "fact()" de chamada recursiva
- E main(), que basicamente, apenas chama ou imprime o valor de fatoral

```c
int fact(int n)
{
    if (n == 1)
        return 1;
    else
        return n * fact(n-1);
}

int main(void)
{
    printf(“%i\n”, fact(5));
}
```

*step by step:*

step| call | Desrcription |step| return | Desrcription|
:--:|:------:|------------|:--:|:------:|-------------|
7|**fact(1)**|fact(2) chama função fact(1)|1|1|sai da pilha (destruído)
6|**fact(2)**|fact(3) chama função fact(2)|2|2*1 ou 2|sai da pilha
5|**fact(3)**|fact(4) chama função fact(3)|3|3*2 ou 6|sai da pilha
4|**fact(4)**|fact(5) chama função fact(4)|4|4*6 ou 24|sai da pilha
3|**fact(5)**|printf chama função fact|5|5*24 ou 120|sai da pilha
2|**printf()**|main chama função printf|6|120|esperava fat. de 5, sai da pilha
1|**main()**|Começamos no início de main|7|concluída|sai da pilha (destuída)
