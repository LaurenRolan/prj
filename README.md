# prj
Projeto Final de Micros

Para utilizar os simbolos criados por nós no gEDA:

- Criar pasta para os símbolos (escolhemos o nome "custom_IC"):
	cd /usr/share/gEDA/sym
	sudo mkdir custom_IC

- Modificar o arquivo geda-clib.scm no diretorio do gEDA:
	adicionar ("custom_IC" "Custom ICs") logo abaixo de "local"

- Copiar os símbolos para o diretório /usr/share/gEDA/sym/custom_IC

Para utilizar as footprints criadas por nós no gEDA:

- Criar pasta para os símbolos (escolhemos o nome "custom_IC"):
	sudo mkdir /usr/share/pcb/newlib/custom_IC

- Copiar as footprint para o diretório /usr/share/pcb/newlib/custom_IC


