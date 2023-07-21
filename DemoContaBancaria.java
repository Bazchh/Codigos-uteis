public class DemoContaBancaria {
    public static void main(String[] args) {
        ContaBancaria conta = new ContaBancaria("Mikael", "88219000293");
        conta.saque(0);
        conta.deposito(-10);
        conta.saque(1);
        conta.deposito(4);
        conta.saque(4);
        
    }
}
