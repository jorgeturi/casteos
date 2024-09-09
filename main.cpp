#include <iostream>

// Definición completa de la clase Complejo
class Complejo {
private:
    double real;
    double imaginario;

public:
    Complejo(double r, double i) : real(r), imaginario(i) {}

    void imprimir() const {
        std::cout << "Complejo: " << real << " + " << imaginario << "i" << std::endl;
    }
};

// Clase Vehiculo que depende de Complejo
class Vehiculo {
private:
    double velocidad;
    double carga;

public:
    Vehiculo(double v, double c) : velocidad(v), carga(c) {}

    // Sobrecarga del operador de conversión a Complejo
    operator Complejo() const {
        return Complejo(velocidad, carga);
    }
};

int main() {
    Vehiculo auto1(60.0, 5.0);
    Complejo c = auto1;  // Conversión implícita a Complejo
    Complejo a(2,1);
    Vehiculo auto2(102,80.55);
    a = (Complejo)auto2;
    a.imprimir();
    c.imprimir();  // Salida: Complejo: 60 + 5i


    Vehiculo auto3(660.0, 55.0);
    Complejo d = static_cast<Complejo>(auto3);  // Conversión explícita con static_cast
    ///como hace la conversion? si tuviera menos atributos como elige donde asignarlos?
    d.imprimir();



    return 0;
}
