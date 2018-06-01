# prj
Projeto Final de Micros

Para utilizar os simbolos criados por nós no gEDA:

- Criar pasta para os símbolos (escolhemos o nome "custom_IC"):
	cd /usr/share/gEDA/sym
	sudo mkdir custom_IC

- Copiar o arquivo geda-clib.scm para o diretorio do gEDA:
	*navegar até o repositório prj do github
	sudo cp geda-clib.scm /usr/share/gEDA/gafrc.d

- Copiar os símbolos para o diretório /usr/share/gEDA/sym/custom_IC

Para utilizar as footprints criadas por nós no gEDA:

- Criar pasta para os símbolos (escolhemos o nome "custom_IC"):
	sudo mkdir /usr/share/pcb/newlib/custom_IC

- Copiar as footprint para o diretório /usr/share/pcb/newlib/custom_IC


