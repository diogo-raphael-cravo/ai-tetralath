/*
* Define um menu, que pode ter submenos e ser dividido em linhas.
* Op��es de um menu s�o sempre strings e podem estar selecionadas ou n�o.
*/
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class menu{
	public:

	/*
	* Cria um novo menu, sem op��es ainda.
	*/
	menu();

	/*
	* Cria uma nova op��o no menu, com as alternativas de argumento.
	* @param _alternativas Vector de strings em que cada elemento � uma alternativa da nova op��o.
	*						A nova op��o � sempre inserida na linha corrente.
	*/
	void criarNovaOpcao(vector<string> _alternativas);

	/*
	* Cria uma nova linha. Depois desta chamada e at� a pr�xima chamada todas novas op��es s�o inseridas nesta linha.
	*/
	void criarNovaLinha();

	/*
	* Seleciona a op��o seguinte � selecionada, na ordem em que foram inseridas no menu.
	* A sele��o � circular.
	* A op��o selecionada � aquela em cujas alternativas pode-se navegar.
	*/
	void selecionarOpcaoSeguinte();

	/*
	* Seleciona a op��o anterior � selecionada, na ordem em que foram inseridas no menu.
	* A sele��o � circular.
	* A op��o selecionada � aquela em cujas alternativas pode-se navegar.
	*/
	void selecionarOpcaoAnterior();

	/*
	* Seleciona a alternativa seguinte � selecionada, na op��o que estiver selecionada.
	* A sele��o � circular.
	*/
	void selecionarAlternativaSeguinte();

	/*
	* Seleciona a alternativa anterior � selecionada, na op��o que estiver selecionada.
	* A sele��o � circular.
	*/
	void selecionarAlternativaAnterior();

	/*
	* @return Um vector de vectors de strings. Cada vector de vectors representa uma linha do menu e cada string que ele cont�m
	*		  � uma op��o selecionada.
	*/
	vector<vector<string> > getAlternativasSelecionadas();

	/*
	* Imprime este menu na tela, evidenciando a op��o escolhida e suas alternativas.
	*/
	void imprimir();

	/*
	* D� nomes �s colunas do menu.
	* @param _nomesColunas Vetor de strings em que cada string � o nome de uma coluna.
	*/
	void nomearColunas(vector<string> _nomesColunas);

	private:
	/*
	* Vetor de linhas do menu. Cada linha � um vetor de vetores de strings.
	* Cada vetor de uma linha corresponde a uma op��o e suas strings s�o as alternativas da op��o.
	*/
	vector<vector<vector<string> > > linhas;

	/*
	* Indica a linha da op��o que est� selecionada.
	*/
	int linhaOpcaoSelecionada;

	/*
	* Indica a posi��o da op��o selecionada (no vector da linha � qual pertence).
	*/
	int colunaOpcaoSelecionada;

	/*
	* Vetor de alternativas selecionadas do menu. Cada linha � um vetor de ints.
	* Cada int corresponde � alternativa que est� selecionada.
	* � um mapeamento de linhas.
	*/
	vector<vector<int> > alternativasSelecionadas;

	/*
	* @return O n�mero de alternativas da op��o selecionada.
	*/
	int getNumeroAlternativasOpcaoSelecionada();

	/*
	* @return O �ndice da alternativa selecionada na op��o selecionada.
	*/
	int getIndiceAlternativaSelecionada();

	/*
	* Nomes exibidos sobre as colunas, caso haja.
	*/
	vector<string> nomesColunas;

	/*
	* Modifica a alternativa selecionada da op��o selecionada.
	* @param _alternativa A alternativa que ser� selecionada.
	* ATEN��O: a fun��o n�o � robusta! Verifique os limites!!
	*/
	void setIndiceAlternativaSelecionadaOpcaoSelecionada(int _alternativa);

	/*
	* @param _linha A linha em que a op��o vai ser procurada.
	* @param _coluna A coluna em que a op��o vai ser procurada.
	* @return A alternativa que foi selecionada da op��o na linha e coluna fornecidas.
	* ATEN��O: a fun��o n�o � robusta! Verifique os limites!!
	*/
	string getNomeAlternativaSelecionadaOpcaoEm(int _linha, int _coluna);
};