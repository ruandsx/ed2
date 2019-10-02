class Aluno
{
public:
  Aluno(string n, string m); // construtor
  ∼Aluno();                  // destrutor
  void info();               // operacoes
  float getNota();
  string getNome();
  void setNota(float valor);
  bool verificaAprovado();

private:
  string nome; // dados
  string matricula;
  float nota;
};