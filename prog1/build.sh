!#/bin/sh
set -xe
javac Teste.java && javac Animal.java && java Teste
rm Teste.class
