# Atividade6

*Código*
<p>
  <ul>
    <li>O código tem como finalidade mostrar o as threads que produzem dados e as threads que consomem dados, utilizando um buffer circular, que quando chega ao final retorna ao valor 0.<br />
    <li>Para começar é solicitado ao usuário a quantidade de produtores e consumidores, o limite e o tamanho do buffer.<br />
    <li>Então os produtores produzem dados para esse buffer e os consumidores consomem os dados dele.<br />
    <li>Após a inserção dos valores atributos o programa vai mostrando qual produtor ou consumidor está produzindo ou consumindo em qual posição do buffer gradativamente.<br />
   </ul></p>
   
   
*Makefile*

<p>
  <ul>
   <li>O Makefile é composto pelos comandos $make, $make run e $make clean.<br />
   <li>O comando $make compila o arquivo tipo C e gera um arquivo binário, nesse caso tendo que ser adicionado o "-pthread" no make para que ele reconheça os comandos dessa biblioteca.<br />
   <li>O $make run usa o arquivo binário para executar o código.<br />
   <li>E o $make clean tem a função de apagar o arquivo binário que foi anteriormente gerado no $make.<br />
</ul></p>
