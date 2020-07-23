<!-- INICIO -->
  <h3 align="center">LLA Injector</h3>
  <p align="center">
    Injetor de DLL simples feito 100% em C++
  </p>
</p>

## Como usar?

* Abra o projeto no [Visual Studio](https://visualstudio.microsoft.com/)
* Entre na "Main.cpp"
* No final do código altere o valor do "PID" para o ID do processo que quer injetar
* Altere o local do "caminhoDaDll" para o local onde esta a dll que quer injetar
* Execute o programa e ele injetara a dll e caso tudo esteja certo ele enviara "Injecao completa!"


## Erros comums

* Ocorreu um erro com o processo

Este erro ocorre por 2 motivo, O ID do processo que você colocou é invalido, ou o programa não tem permissão, Se o processo que quer injetar estiver em modo administrador execute o programa como administrador também, Se não funcionar o processo é algo do sistema ou possui algo que protege ele desse tipo de injeção

* Programa crasha depois de iniciar

Este erro pode ser por diversos motivos, mas um dos mais comum é quando o caminho da dll esta incorreto ou o processo bloqueia este tipo de injeção