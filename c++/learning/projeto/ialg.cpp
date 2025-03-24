/*Membros da equipe (Grupo 20):
 * Alexandre de Castro Nunes Borges Filho
 * Ana Clara Moreira Viana
 * Maycon Henrique Soares de Sousa
Tema: Guilda de Herois*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <sys/stat.h>
#include <cmath>
#include <algorithm>

using namespace std;

// Vars de uso na Main
// Info sobre membros da guilda
struct guildMember
{
	int id;
	string name;
	char rank;
	float success;
	bool active;
};

//ASCII Art
void printFile() {
	cout << "      ______ _____ _      ______      " << endl;
	cout << "     |  ____|_   _| |    |  ____|     " << endl;
	cout << "     | |__    | | | |    | |__        " << endl;
	cout << "     |  __|   | | | |    |  __|       " << endl;
	cout << "     | |     _| |_| |____| |____      " << endl;
	cout << "     |_|    |_____|______|______|     " << endl;
}

void printView() {
	cout << " __      _______ ________          __" << endl;
	cout << " \\ \\    / /_   _|  ____\\ \\        / /" << endl;
	cout << "  \\ \\  / /  | | | |__   \\ \\  /\\  / / " << endl;
	cout << "   \\ \\/ /   | | |  __|   \\ \\/  \\/ /  " << endl;
	cout << "    \\  /   _| |_| |____   \\  /\\  /   " << endl;
	cout << "     \\/   |_____|______|   \\/  \\/    " << endl;
}

void printMod() {
	cout << "         __  __  ____  _____         " << endl;
	cout << "        |  \\/  |/ __ \\|  __ \\     " << endl;
	cout << "        | \\  / | |  | | |  | |      " << endl;
	cout << "        | |\\/| | |  | | |  | |      " << endl;
	cout << "        | |  | | |__| | |__| |       " << endl;
	cout << "        |_|  |_|\\____/|_____/       " << endl;
}

void printBusca() {
	cout << "  ____  _    _  _____  _____          " << endl;
	cout << " |  _ \\| |  | |/ ____|/ ____|   /\\    " << endl;
	cout << " | |_) | |  | | (___ | |       /  \\   " << endl;
	cout << " |  _ <| |  | |\\___ \\| |      / /\\ \\  " << endl;
	cout << " | |_) | |__| |____) | |____ / ____ \\ " << endl;
	cout << " |____/ \\____/|_____/ \\_____/_/    \\_\\ " << endl;
}

void printExit() {
	cout << "       ________   _______ _______     " << endl;
	cout << "      |  ____\\ \\ / /_   _|__   __|  " << endl;
	cout << "      | |__   \\ V /  | |    | |      " << endl;
	cout << "      |  __|   > <   | |    | |       " << endl;
	cout << "      | |____ / . \\ _| |_   | |      " << endl;
	cout << "      |______/_/ \\_\\_____|  |_|     " << endl;
}

void printSave() {
	cout << "       _____    __      ________      " << endl;
	cout << "      / ____|  /\\ \\    / /  ____|   " << endl;
	cout << "     | (___   /  \\ \\  / /| |__      " << endl;
	cout << "      \\___ \\ / /\\ \\ \\/ / |  __|  " << endl;
	cout << "      ____) / ____ \\  /  | |____     " << endl;
	cout << "     |_____/_/    \\_\\/   |______|   " << endl;
}

// Visualizar um trecho especifico do arquivo
void displaySection(int memberCount, guildMember *memberList, int begin, int end)
{
	if (end > memberCount) {
		end = memberCount - 1;
	}

	cout << endl;

	for (int i = begin; i <= end; i++)
	{
		if (memberList[i].rank != 'U')
		{
			cout << "ID:         " << memberList[i].id << endl;
			cout << "Nome:       " << memberList[i].name << endl;
			cout << "Rank:       " << memberList[i].rank << endl;
			cout << "Successo:   " << memberList[i].success << endl;
			cout << "Atividade:  " << memberList[i].active << endl << endl;
		}
	}
}

// Visualizar o aquivo inteiro
void displayAll(int memberCount, guildMember *memberList)
{

	cout << " __      _______ ________          __" << endl;
	cout << " \\ \\    / /_   _|  ____\\ \\        / /" << endl;
	cout << "  \\ \\  / /  | | | |__   \\ \\  /\\  / / " << endl;
	cout << "   \\ \\/ /   | | |  __|   \\ \\/  \\/ /  " << endl;
	cout << "    \\  /   _| |_| |____   \\  /\\  /   " << endl;
	cout << "     \\/   |_____|______|   \\/  \\/    " << endl;
	cout << "======================================" << endl << endl;

	for (int i = 0; i < memberCount; i++)
	{
		if (memberList[i].rank != 'U')
		{
			cout << "ID:         " << memberList[i].id << endl;
			cout << "Nome:       " << memberList[i].name << endl;
			cout << "Rank:       " << memberList[i].rank << endl;
			cout << "Successo:   " << memberList[i].success << endl;
			cout << "Atividade:  " << memberList[i].active << endl
				 << endl;
		}
	}
}

// funcAux para printar variaveis para debuggar o codigo
void varsDebug(int memberCount, guildMember *memberList)
{

	for (int i = 0; i < memberCount; i++)
	{
		// if (memberList[i].rank != 'U') {
		cout << "ID:         " << memberList[i].id << endl;
		cout << "Nome:       " << memberList[i].name << endl;
		cout << "Rank:       " << memberList[i].rank << endl;
		cout << "Successo:   " << memberList[i].success << endl;
		cout << "Atividade:  " << memberList[i].active << endl
			 << endl;
		//}
	}

	cout << endl
		 << memberCount << " Fim de teste de Variaveis." << endl;
}

// Busca BInaria
// Busca Nome
int binarySearchByName(guildMember *arr, int size, string name)
{
	int left = 0, right = size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid].name == name)
		{
			return mid;
		}
		if (arr[mid].name < name)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
// Busca ID
int binarySearchById(guildMember *arr, int size, int id)
{
	int left = 0, right = size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid].id == id)
		{
			return mid;
		}
		if (arr[mid].id < id)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
// Funcao Sort - Ana (Quicksort Int)
// Particao Int
int partition(guildMember *vetor, int low, int high)
{
	int pivotValue = vetor[high].id;
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (vetor[j].id <= pivotValue)
		{
			swap(vetor[i], vetor[j]);
			i++;
		}
	}

	swap(vetor[i], vetor[high]);
	return i;
}
// Particao Strings
int partitionString(guildMember *vetor, int low, int high)
{
	string pivotValue = vetor[high].name;
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (vetor[j].name <= pivotValue)
		{
			swap(vetor[i], vetor[j]);
			i++;
		}
	}

	swap(vetor[i], vetor[high]);
	return i;
}
// Quick int
void quicksortInt(guildMember *vetor, int low, int high)
{
	while (vetor[high].rank == 'U')
	{
		high--;
	}

	if (low < high)
	{
		int pivotIndex = partition(vetor, low, high);
		quicksortInt(vetor, low, pivotIndex - 1);
		quicksortInt(vetor, pivotIndex + 1, high);
	}
}
// Quick string
void quicksortString(guildMember *vetor, int low, int high)
{
	while (vetor[high].rank == 'U')
	{
		high--;
	}

	if (low < high)
	{
		int pivotIndex = partitionString(vetor, low, high);
		quicksortString(vetor, low, pivotIndex - 1);
		quicksortString(vetor, pivotIndex + 1, high);
	}
}
// Get info da Guilda
// Get de arquivo csv
guildMember *csvGet(string name, int &memberCount)
{
	int i = 0;
	ifstream openFile(name);
	string line;
	string temp;

	getline(openFile, line);
	stringstream inputString(line);

	memberCount = 5;
	guildMember *memberAux = new guildMember[memberCount];

	while (getline(openFile, line))
	{
		inputString.clear();
		inputString.str(line);

		getline(inputString, temp, ',');
		memberAux[i].id = atoi(temp.c_str());

		getline(inputString, temp, ',');
		memberAux[i].name = temp;

		getline(inputString, temp, ',');
		memberAux[i].rank = temp[0];

		getline(inputString, temp, ',');
		memberAux[i].success = atof(temp.c_str());

		getline(inputString, temp);
		if (temp == "Ativo")
		{
			memberAux[i].active = true;
		}
		else
		{
			memberAux[i].active = false;
		}

		i++;

		if (i == memberCount)
		{
			memberCount += 5;
			guildMember *memberTemp = new guildMember[memberCount];
			copy(memberAux, memberAux + (memberCount - 5), memberTemp);
			memberAux = memberTemp;
		}
	}

	while (i < memberCount)
	{
		memberAux[i].id = 0;
		memberAux[i].name = "CONVITE DISPONIVEL";
		memberAux[i].rank = 'U';
		memberAux[i].success = 0;
		memberAux[i].active = false;

		i++;
	}

	openFile.close();

	return memberAux;
}
// Get arquivo dat
guildMember *datGet(string name, int &memberCount)
{
	fstream r;
	int i = 0;
	r.open(name, ios::in | ios::binary);

	ifstream fileSize(name, ios::binary | ios::ate);
	int size = sizeof(int) + sizeof(char[50]) + sizeof(char) + sizeof(float) + sizeof(bool);
	size = fileSize.tellg() / size;
	fileSize.close();

	memberCount = ((int)ceil((double)size / 5)) * 5;

	guildMember *memberAux = new guildMember[memberCount];

	if (r.is_open())
	{
		while (i < size)
		{
			char charString[50];

			r.read(reinterpret_cast<char *>(&memberAux[i].id), sizeof(int));
			r.read(reinterpret_cast<char *>(&charString), sizeof(char[50]));
			memberAux[i].name = "";
			for (int j = 0; j < 50; j++)
			{
				if (charString[j] != '0')
				{
					memberAux[i].name += charString[j];
				}
			}
			r.read(reinterpret_cast<char *>(&memberAux[i].rank), sizeof(char));
			r.read(reinterpret_cast<char *>(&memberAux[i].success), sizeof(float));
			r.read(reinterpret_cast<char *>(&memberAux[i].active), sizeof(bool));

			i++;
		}
	}
	else
	{
		cout << "Nao foi possivel abrir o arquivo. DAT" << endl;
	}

	while (i < memberCount)
	{
		memberAux[i].id = 0;
		memberAux[i].name = "CONVITE DISPONIVEL";
		memberAux[i].rank = 'U';
		memberAux[i].success = 0;
		memberAux[i].active = false;

		i++;
	}

	r.close();
	return memberAux;
}
// Get
guildMember *infoGet(string name, int &memberCoun)
{

	if (name.size() > 4 && name.substr(name.size() - 4) == ".csv")
	{
		return csvGet(name, memberCoun);
	}
	else
	{
		return datGet(name, memberCoun);
	}
}
// Salvamento
// Salvar Dat
void saveDat(guildMember *memberList, int memberCount, string nome)
{

	nome += ".dat";

	ofstream{nome};
	fstream save;
	save.open(nome, ios::out | ios::binary);

	char includeInactive;
	printSave();
	cout << "======================================" << endl;
	cout << "      INCLUIR MEMBROS INATIVOS?       " << endl;
	cout << "         S (SIM) | N (NAO)            " << endl;
	cout << "======================================" << endl;
	cin >> includeInactive;

	bool includeInactiveMembers = (includeInactive == 'S' || includeInactive == 's');
	if (save.is_open())
	{
		for (int i = 0; i < memberCount; i++)
		{
			if (memberList[i].rank != 'U' && (memberList[i].active || includeInactiveMembers))
			{
				char charString[50];
				for (int j = 0; j < 50; j++)
				{
					if (j < (int)memberList[i].name.size())
					{
						charString[j] = memberList[i].name[j];
					}
					else
					{
						charString[j] = '0';
					}
				}

				if (memberList[i].rank != 'U')
				{
					save.write(reinterpret_cast<char *>(&memberList[i].id), sizeof(int));
					save.write(reinterpret_cast<char *>(&charString), sizeof(char[50]));
					save.write(reinterpret_cast<char *>(&memberList[i].rank), sizeof(char));
					save.write(reinterpret_cast<char *>(&memberList[i].success), sizeof(float));
					save.write(reinterpret_cast<char *>(&memberList[i].active), sizeof(bool));
				}
			}
		}
	}
	else
	{
		cout << "Nao foi possivel abrir o arquivo" << endl;
		save.close();
		return;
	}

	save.close();
};
// Salvar CSV
void saveCSV(guildMember *memberList, int memberCount, string fileName)
{

	fileName += ".csv";

	ofstream outFile(fileName);
	if (!outFile.is_open())
	{
		cerr << "Erro ao abrir o arquivo para gravacao." << endl;
		return;
	}

	outFile << "ID,Name,Rank,Success,Atividade" << endl;

	char includeInactive;
	printSave();
	cout << "======================================" << endl;
	cout << "      INCLUIR MEMBROS INATIVOS?       " << endl;
	cout << "         S (SIM) | N (NAO)            " << endl;
	cout << "======================================" << endl;
	cin >> includeInactive;

	bool includeInactiveMembers = (includeInactive == 'S' || includeInactive == 's');

	for (int i = 0; i < memberCount; i++)
	{
		if (memberList[i].rank != 'U' && (memberList[i].active || includeInactiveMembers))
		{
			outFile << memberList[i].id << ','
					<< memberList[i].name << ','
					<< memberList[i].rank << ','
					<< memberList[i].success << ','
					<< (memberList[i].active ? "Ativo" : "Inativo") << endl;
		}
	}

	outFile.close();
}
// Leitura de Arquivos
// Handler arquivo
void getFileByName(string &nome)
{
	bool exist = false;
	struct stat sb;

	printFile();
	cout << "======================================" << endl;
	cout << "       DIGITE O NOME DO ARQUIVO       " << endl;
	cout << " EXTENSOES PERMITIDAS: '.dat' / '.csv'" << endl;
	cout << "======================================" << endl;
	cin >> nome;
	nome = "./guildList/" + nome;

	exist = (stat(nome.c_str(), &sb) == 0);

	if ((nome.size() > 4 && nome.substr(nome.size() - 4) != ".csv") && (nome.size() > 4 && nome.substr(nome.size() - 4) != ".dat"))
	{
		exist = false;
	}

	while (!exist)
	{
		system("cls||clear");
		printFile();
		cout << "======================================" << endl;
		cout << "     ARQUIVO AUSENTE OU INVALIDO      " << endl;
		cout << "     VERIFIQUE A PASTA GUILDLIST	   " << endl;
		cout << "======================================" << endl;
		cin >> nome;
		nome = "./guildList/" + nome;

		exist = (stat(nome.c_str(), &sb) == 0);

		if ((nome.size() > 4 && nome.substr(nome.size() - 4) != ".csv") && (nome.size() > 4 && nome.substr(nome.size() - 4) != ".dat"))
		{
			exist = false;
		}
	}
}
// Handler da pasta
bool folderHandler(string &nome)
{
	bool path;
	struct stat sb;

	if (stat("./guildList", &sb) != 0)
	{
		string dummy;

		printFile();
		cout << "======================================" << endl;
		cout << "       PASTA GUILDLUIST AUSENTE       " << endl;
		cout << "======================================" << endl;
		cout << "| Digite qualquer valor para sair.   |" << endl;
		cout << "--------------------------------------" << endl;

		cin >> dummy;
		path = false;

		return path;
	}
	else
	{
		path = true;
	}

	if (path)
	{
		getFileByName(nome);
	}

	system("cls||clear");

	return path;
}
// Redimensionar Vetor
// Aumenta Vetor
guildMember *expandArray(guildMember *memberList, int &memberCount)
{
	guildMember newMember;
	printMod();
	cout << "======================================" << endl;
	cout << "          INSIRA NOVOS DADOS          " << endl;
	cout << "======================================" << endl;
	cout << "ID:         ";
	cin >> newMember.id;
	cout << "Nome:       ";
	cin.ignore(); // Ignorar nova linha residual
	getline(cin, newMember.name);
	cout << "Rank:       ";
	cin >> newMember.rank;
	newMember.rank = (char)toupper(newMember.rank);
	cout << "Sucesso:    ";
	cin >> newMember.success;
	cout << "1 PARA ATIVO | 0 PARA NAO" << endl;
	cout << "Atividade:  ";
	cin >> newMember.active;

	// Verificar se ha espaco para novos membros ou expandir o vetor
	bool inserted = false;
	int i = 0;
	guildMember *tempList = new guildMember[memberCount];
	copy(memberList, memberList + memberCount, tempList);
	while (!inserted && (i != memberCount))
	{
		if (tempList[i].rank == 'U')
		{
			tempList[i] = newMember;
			inserted = true;
		}
		i++;
	}

	if (!inserted)
	{
		// Expandir o vetor se nao houver espaco
		delete[] tempList;
		tempList = new guildMember[memberCount + 5];
		copy(memberList, memberList + memberCount, tempList);
		memberCount += 5;
		tempList[i] = newMember;
		i++;
		while (i != memberCount)
		{
			tempList[i].id = 0;
			tempList[i].name = "CONVITE DISPONIVEL";
			tempList[i].rank = 'U';
			tempList[i].success = 0;
			tempList[i].active = false;
			i++;
		}
	}

	delete[] memberList;

	return tempList;
}
// Diminui Vetor
guildMember *shrinkArray(guildMember *memberList, int &memberCount)
{
	memberCount -= 5;
	guildMember *tempList = new guildMember[memberCount];

	copy(memberList, memberList + memberCount, tempList);

	delete[] memberList;

	return tempList;
}
// Salvamento de arquivo
void fileSet(guildMember *memberList, int memberCount, string nome)
{
	bool loop = true;
		printSave();
		cout << "======================================" << endl;
		cout << "             SALVAR ARQUIVO           " << endl;
		cout << "    1. ARQUIVO CSV | 2. ARQUIVO DAT   " << endl;
		cout << "======================================" << endl;

	while (loop)
	{
		int num = 0;
		cin >> num;
		system("cls||clear");
		switch (num)
		{
		case 1:
			saveCSV(memberList, memberCount, nome);
			loop = false;
			break;
		case 2:
			saveDat(memberList, memberCount, nome);
			loop = false;
			break;
		default:
			cout << "======================================" << endl;
			cout << "             OPCAO INVALIDA           " << endl;
			cout << "    1. ARQUIVO CSV | 2. ARQUIVO DAT   " << endl;
			cout << "======================================" << endl;
			break;
		}
	}
}
// Inserir e remover cadastros
void modifyMembers(guildMember *&memberList, int &memberCount)
{
	int choice;

	printMod();
	cout << "======================================" << endl;
	cout << "  SELECIONE UMA OPCAO DE MODIFICACAO  " << endl;
	cout << "======================================" << endl;
	cout << "| 1. Inserir novo membro             |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "| 2. Remover membro por ID           |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "| 3. Editar membro por ID            |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "| 4. Voltar                          |" << endl;
	cout << "--------------------------------------" << endl;
	cin >> choice;

	system("cls||clear");

	switch (choice)
	{
	case 1:
	{
		memberList = expandArray(memberList, memberCount);

		system("cls||clear");
		printMod();

		cout << "======================================" << endl;
		cout << "   NOVO MEMBRO INSERIDO COM SUCESSO   " << endl;
		cout << "======================================" << endl;
		break;
	}
	case 2:
	{
		int idToRemove;
		printMod();
		cout << "======================================" << endl;
		cout << "  DIGITE O ID DO MEMBRO PARA REMOCAO  " << endl;
		cout << "======================================" << endl;
		cin >> idToRemove;
		int removedIndex = -1;
		int i = 0;
		while (removedIndex == -1 && i < memberCount)
		{
			if (memberList[i].id == idToRemove)
			{
				removedIndex = i;
			}
			i++;
		}

		i = removedIndex;

		system("cls||clear");
		printMod();

		if (removedIndex != -1)
		{
			guildMember *tempList = new guildMember[memberCount];

			copy(memberList, memberList + i, tempList);
			copy(memberList + (i + 1), memberList + memberCount, tempList + i);

			delete[] memberList;

			memberList = tempList;

			/*
			// Compacta o vetor
			while (i < memberCount - 1) {
				memberList[i] = memberList[i + 1];
				i++;
			}
			*/

			memberList[memberCount - 1].id = 0;
			memberList[memberCount - 1].name = "CONVITE DISPONIVEL";
			memberList[memberCount - 1].rank = 'U';
			memberList[memberCount - 1].success = 0;
			memberList[memberCount - 1].active = false;

			i = memberCount - 5;
			bool empty = true;

			while (i < memberCount && empty)
			{
				if (memberList[i].rank != 'U')
				{
					empty = false;
				}
				i++;
			}

			if (empty)
			{
				memberList = shrinkArray(memberList, memberCount);
			}

			cout << "======================================" << endl;
			cout << "     MEMBRO REMOVIDO COM SUCESSO      " << endl;
			cout << "======================================" << endl;
		}
		else
		{
			cout << "======================================" << endl;
			cout << "          ID NAO ENCONTRADO           " << endl;
			cout << "======================================" << endl;
		}
		break;
	}
	case 3:
	{
		int idToEdit;
		printMod();
		cout << "======================================" << endl;
		cout << "  DIGITE O ID DO MEMBRO PARA EDICAO   " << endl;
		cout << "======================================" << endl;
		cin >> idToEdit;
		int editIndex = -1;
		int i = 0;
		while (editIndex == -1 && i < memberCount)
		{
			if (memberList[i].id == idToEdit)
			{
				editIndex = i;
			}
			i++;
		}

		i = editIndex;

		system("cls||clear");
		printMod();

		if (editIndex != -1)
		{
			cout << "======================================" << endl;
			cout << "           MEMBRO ENCONTRADO          " << endl;
			cout << "======================================" << endl;
			cout << "ID:         " << memberList[i].id << endl;
			cout << "Nome:       " << memberList[i].name << endl;
			cout << "Rank:       " << memberList[i].rank << endl;
			cout << "Successo:   " << memberList[i].success << endl;
			cout << "Atividade:  " << memberList[i].active << endl;

			cout << "======================================" << endl;
			cout << "          INSIRA NOVOS DADOS          " << endl;
			cout << "======================================" << endl;
			cout << "ID:         " << memberList[i].id << "    (NAO EDITAVEL)" << endl;

			cout << "Nome:       ";
			cin.ignore(); // Ignorar nova linha residual
			getline(cin, memberList[i].name);

			cout << "Rank:       ";
			cin >> memberList[i].rank;
			memberList[i].rank = (char)toupper(memberList[i].rank);

			cout << "Successo:   ";
			cin >> memberList[i].success;



			cout << "1 PARA ATIVO | 0 PARA NAO" << endl;
			cout << "Atividade:  ";
			cin >> memberList[i].active;

			system("cls||clear");
			printMod();

			cout << "======================================" << endl;
			cout << "      MEMBRO EDITADO COM SUCESSO      " << endl;
			cout << "======================================" << endl;

		}
		else
		{
			cout << "======================================" << endl;
			cout << "          ID NAO ENCONTRADO           " << endl;
			cout << "======================================" << endl;
		}
		break;
	}
	case 4:
	{
		return;
	}
	default:
		cout << "======================================" << endl;
		cout << "            OPCAO INVALIDA            " << endl;
		cout << "======================================" << endl;
		break;

	}
}
// Tela Principal
void telaMain(guildMember *&memberList, int &memberCount)
{

	// varsDebug(memberCount, memberList);
	cout << "     _____       _ _     _            " << endl;
	cout << "    / ____|     (_) |   | |           " << endl;
	cout << "   | |  __ _   _ _| | __| | __ _      " << endl;
	cout << "   | | |_ | | | | | |/ _` |/ _` |     " << endl;
	cout << "   | |__| | |_| | | | (_| | (_| |     " << endl;
	cout << "    \\____/ \\__,_|_|_|\\__,_|\\__,_| " << endl;
	cout << "======================================" << endl;
	cout << "          SELECIONE UMA OPCAO         " << endl;
	cout << "======================================" << endl;
	cout << "| 1. Busca por Nome                  |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "| 2. Busca por ID                    |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "| 3. Modificar Membros               |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "| 4. Visualizar arquivo inteiro      |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "| 5. Visualizar um trecho especifico |" << endl;
	cout << "--------------------------------------" << endl;
	cout << "| 6. Sair/Salvar                     |" << endl;
	cout << "--------------------------------------" << endl;
	int choice;
	cin >> choice;

	system("cls||clear");
	string name;
	string temp;
	int id = 0;
	int index;

	switch (choice)
	{
	case 1:
		printBusca();
		cout << "======================================" << endl;
		cout << "       DIGITE O NOME PARA BUSCA       " << endl;
		cout << "======================================" << endl;
		cin.ignore(); // Para ignorar o caractere de nova linha residual no buffer
		getline(cin, name);
		// Certifique-se de que a lista esteja ordenada por nome antes da busca
		quicksortString(memberList, 0, memberCount - 1);
		index = binarySearchByName(memberList, memberCount, name);

		system("cls||clear");

		if (index != -1)
		{
			printBusca();
			cout << "======================================" << endl;
			cout << "           MEMBRO ENCONTRADO          " << endl;
			cout << "======================================" << endl;
			cout << "ID:         " << memberList[index].id << endl;
			cout << "Nome:       " << memberList[index].name << endl;
			cout << "Rank:       " << memberList[index].rank << endl;
			cout << "Successo:   " << memberList[index].success << endl;
			cout << "Atividade:  " << memberList[index].active << endl;
		}
		else
		{
			printBusca();
			cout << "======================================" << endl;
			cout << "         MEMBRO NAO ENCONTRADO        " << endl;
			cout << "======================================" << endl;
		}
		break;
	case 2:
		printBusca();
		cout << "======================================" << endl;
		cout << "        DIGITE O ID PARA BUSCA        " << endl;
		cout << "======================================" << endl;
		cin >> temp;

		system("cls||clear");

		if (temp.length() > 9)
		{
			printBusca();
			cout << "======================================" << endl;
			cout << "               ID INVALIDO            " << endl;
			cout << "======================================" << endl;
		}
		else
		{
			printBusca();
			id = atoi(temp.c_str());
			quicksortInt(memberList, 0, memberCount - 1);
			index = binarySearchById(memberList, memberCount, id);
			if (index != -1)
			{
				cout << "======================================" << endl;
				cout << "           MEMBRO ENCONTRADO          " << endl;
				cout << "======================================" << endl;
				cout << "ID:         " << memberList[index].id << endl;
				cout << "Nome:       " << memberList[index].name << endl;
				cout << "Rank:       " << memberList[index].rank << endl;
				cout << "Successo:   " << memberList[index].success << endl;
				cout << "Atividade:  " << memberList[index].active << endl;
			}
			else
			{
				cout << "======================================" << endl;
				cout << "         MEMBRO NAO ENCONTRADO        " << endl;
				cout << "======================================" << endl;
			}
		}
		break;
	case 3:
		quicksortInt(memberList, 0, memberCount - 1);
		modifyMembers(memberList, memberCount);
		break;
	case 4:
		printView();
		cout << "======================================" << endl;
		cout << "     DIGITE O METODO DE ORDENACAO     " << endl;
		cout << "           1. ID / 2. NOME            " << endl;
		cout << "======================================" << endl;
		cin >> temp;
		
		if(temp == "1"){
			quicksortInt(memberList, 0, memberCount - 1);
		} else {
			quicksortString(memberList, 0, memberCount - 1);
		}

		system("cls||clear");

		displayAll(memberCount, memberList);
		break;
	case 5:
		printView();
		cout << "======================================" << endl;
		cout << "     DIGITE O METODO DE ORDENACAO     " << endl;
		cout << "           1. ID / 2. NOME            " << endl;
		cout << "======================================" << endl;
		cin >> temp;
		if(temp == "1"){
			quicksortInt(memberList, 0, memberCount - 1);
		} else {
			quicksortString(memberList, 0, memberCount - 1);
		}

		system("cls||clear");

		printView();
		cout << "======================================" << endl;
		cout << "           DEFINA OS INDICES          " << endl;
		cout << "              0 = INICIO              " << endl;
		cout << "======================================" << endl;
		cout << "INICIAL: ";
		int begin;
		cin >> begin;
		cout << "FINAL:   ";
		int end;
		cin >> end;
		cout << "======================================" << endl;
		displaySection(memberCount, memberList, begin, end);
		break;
	case 6:
		break;
	default:
		cout << "======================================" << endl;
		cout << "             OPCAO INVALIDA           " << endl;
		cout << "======================================" << endl;
		break;
	}
}
// Funcao para salvar as alteracoes
bool saveChanges()
{
	char choice;
		printSave();
		cout << "======================================" << endl;
		cout << "      DESEJA SALVAR ALTERACOES?       " << endl;
		cout << "         S (SIM) | N (NAO)            " << endl;
		cout << "======================================" << endl;
		cin >> choice;
		system("cls||clear");
	return (choice == 'S' || choice == 's');
}
// Main
int main()
{
	// Vars
	guildMember *memberList; // Guild Array
	string nomeArquivo;
	int memberCount;

	// Inicializando variaveis
	if (folderHandler(nomeArquivo)) {
		memberList = infoGet(nomeArquivo, memberCount);
		nomeArquivo = nomeArquivo.erase(nomeArquivo.length() - 4);

		// Loop de tela principal
		bool running = true;
		while (running)
		{
			telaMain(memberList, memberCount);
			char continueChoice;

			printExit();
			cout << "======================================" << endl;
			cout << "           DESEJA CONTINUAR?          " << endl;
			cout << "      S (CONTINUA) | N (FINALIZA)     " << endl;
			cout << "======================================" << endl;
			cin >> continueChoice;
			system("cls||clear");
			if (continueChoice == 'N' || continueChoice == 'n')
			{
				running = false;
			}
		}

		// Salvar arquivo no final.
		//  Pergunta se deseja salvar antes de sair
		if (saveChanges())
		{
			fileSet(memberList, memberCount, nomeArquivo);
		}

		delete[] memberList;
	}

	return 0;
}