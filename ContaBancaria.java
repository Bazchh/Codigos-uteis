public class ContaBancaria {
    private String nome;
    private String cpf;
    private int saldo;

    ContaBancaria(String nome, String cpf) {
        this.nome = nome;
        this.cpf = cpf;
        this.saldo = 0;
    }

    public void deposito(int deposito) {
        if(deposito > 0){
           this.saldo += deposito;
           System.out.println("\nDeposito efetuado com sucesso: +" + deposito); 
        } else if (deposito <= 0 ){
            System.out.println("\nInsira um valor valido para realizar o deposito (maior que zero)");
        }
        
    }

    public void saque(int saque) {
        
        if (saque > 0) {
            if (this.saldo - saque < 0) {
                System.out.println("\nNão possui saldo suficiente para realizar o saque");
            } else if (this.saldo >= 0) {
                this.saldo -= saque;
                System.out.println("\nSaque efetuado com sucesso: -" + saque);
            } else {
                System.out.println("\nNão foi possivel realizar o saque");
            }

        } else if(saque <= 0){
            System.out.println("\nInsira um valor valido para realizar o saque (maior que zero)");
        }
        

    }

    public String getNome() {
        return nome;
    }

    public String getCpf() {
        return cpf;
    }

    public int getSaldo() {
        return saldo;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public void setSaldo(int saldo) {
        this.saldo = saldo;
    }

    @Override
    public String toString() {
        return "\nNome do cliente: " + this.nome + "\nCPF do cliente: " + this.cpf + "\nMontante na conta: "
                + this.saldo;
    }

}
