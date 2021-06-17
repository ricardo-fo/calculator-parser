# Calculator Parser  

> Grupo:  
> [Alexandre Saura][1]  
> [Fábio Thomaz][2]  
> [Ricardo Oliveira][3]  
> [Rodrigo Suarez][4]  
>  
> Prof.: José Fontebasso Neto.  
> Universidade Católica de Santos, 2021.  

[1]: https://github.com/alexandresaura  
[2]: https://github.com/FabioTV/  
[3]: https://github.com/ricardo-fo/  
[4]: https://github.com/rodrigosmoreira/  

## Analisador sintático de uma calculadora em notação pós-fixa  
Este projeto é uma aplicação capaz de fazer a análise sintática de uma entrada, em notação pós-fixa, de *inputs* de uma calculadora. Através dos tokens inseridos como entrada, no formato *<dígito>* ou *<operador>* ou *<comando>*, o programa deve indicar os estados das análises e se a entrada é válida ou não segundo a gramática da calculadora pós-fixa.  

## Recursos necessários  
Para executar o projeto é necessário um compilador de da linguagem C.  

## Como executar a aplicação  
### No Linux  
Para compilar, execute no terminal:  
```
make
```
Em seguida, para executar a aplicação:  
```
make run
```
Caso deseje excluir os arquivos objeto:  
```
make clean
```
Ou excluir o arquivo executável:  
```
make mrproper
```

## Tarefas  
- [x] Criar o repositório;  
- [x] Ler a entrada do usuário;  
- [x] Transformar a entrada em um vetor de tokens;
- [x] Fazer a análise léxica da entrada;  
- [ ] Criar a tabela sintática;  
- [ ] Criar a pilha sintática;  
- [ ] Criar a tabela de ações;  
- [ ] Criar a tabela de *goto*;  
- [ ] Fazer a análise sintática.  
