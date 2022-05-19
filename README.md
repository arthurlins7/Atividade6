# Atividade6

*Código*
<p>
  <ul>
    <li>O código tem como finalidade fazer a soma de todos os elementos de uma matriz quadrada que será fornecida pelo usuário.<br />
    <li>Para começar é solicitado ao usuário a quantidade de linhas e de colunas, necessitando de apenas um número já que a matriz é quadrada.<br />
    <li>Após receber o tamanho da matriz threads foram utilizadas para receber os números que irão compor a matriz e montá-la.<br />
    <li>Com a montagem da matriz completa o programa somará todos os números dela e retornará ao usuário o resultado final.<br />
   </ul></p>
   
   
*Makefile*

<p>
  <ul>
   <li>O Makefile é composto pelos comandos $make, $make run e $make clean.<br />
   <li>O comando $make compila o arquivo tipo C e gera um arquivo binário, nesse caso tendo que ser adicionado o "-pthread" no make para que ele reconheça os comandos dessa biblioteca.<br />
   <li>O $make run usa o arquivo binário para executar o código.<br />
   <li>E o $make clean tem a função de apagar o arquivo binário que foi anteriormente gerado no $make.<br />
</ul></p>
