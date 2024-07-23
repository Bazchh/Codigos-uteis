class Estudante:
    def __init__(self, nome, mat):
        self.nome = nome
        self.mat = mat

class No:
    def __init__(self, dado=None):
        self.dado = dado
        self.prox = None

class Pilha:
    def __init__(self):
        self.topo = None
    
    def inserir(self, dado):
        novo = No(dado)
        novo.prox = self.topo
        self.topo = novo
    
    def imprimir(self):
        pi = self.topo
        while pi:
            print(f"Nome: {pi.dado.nome}\nMatricula: {pi.dado.mat}\n")
            pi = pi.prox
    
    def remover(self):
        if not self.topo:
            print("A pilha está vazia")
        else:
            pi = self.topo
            self.topo = pi.prox
            del pi
            print("Elemento removido com sucesso!")
    
    def vazia(self):
        if not self.topo:
            return True
        else:
            return False
    
    def pegar_topo(self):
        if not self.topo:
            print("Pilha vazia")
        else:
            print(f"{self.topo.dado.nome} {self.topo.dado.mat}")
    
    def inverter(self):
        aux = Pilha()
        while self.topo:
            dado = self.topo.dado
            aux.inserir(dado)
            self.remover()
        self.topo = aux.topo
        print("Pilha invertida com sucesso!")


def menu():
    print("\n========Escolha uma opção=========")
    print("1 - Adicionar pilha")
    print("2 - Mostrar pilha")
    print("3 - Remover elemento")
    print("4 - Verificar pilha")
    print("5 - Pegar topo")
    print("6 - Inverter")
    print("7 - Sair\n")


def ler():
    nome = input("Insira o nome do estudante: ")
    mat = int(input("Insira a matrícula do estudante: "))
    return Estudante(nome, mat)


if __name__ == "__main__":
    pilha = Pilha()
    op = None
    while op != 7:
        menu()
        op = int(input("Escolha uma opção: "))  # Erro 1: Não há tratamento para entrada que não seja um número inteiro.
        if op == 1:
            estudante = ler()
            pilha.inserir(estudante)
        elif op == 2:
            pilha.imprimir()
        elif op == 3:
            pilha.remover()
        elif op == 4:
            if pilha.vazia():
                print("A pilha está vazia")
            else:
                print("A pilha contém elementos")
        elif op == 5:
            pilha.pegar_topo()
        elif op == 6:
            pilha.inverter()
        else:
            print("Opção inválida. Escolha uma opção de 1 a 7.")  # Erro 2: Mensagem de erro genérica para opções inválidas.

    print("Programa encerrado")
