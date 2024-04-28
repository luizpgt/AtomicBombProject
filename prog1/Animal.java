public class Animal {
  private String nome;
  private String raca;
  private int idade;

  public void alimenta() {
    System.out.println("hm hm " + getNome());
  }

  public abstract void caricia();

  // getters and settes
  public int getIdade() {
    return idade;
  }

  public String getNome() {
    return nome;
  }

  public String getRaca() {
    return raca;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setRaca(String raca) {
    this.raca = raca;
  }

  public void setIdade(int idade) {
    this.idade = idade;
  }
}
