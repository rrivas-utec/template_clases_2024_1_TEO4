//
// Created by rrivas on 26/04/2024.
//

#ifndef TEMPLATE_CLASES_PLANTILLAS_H
#define TEMPLATE_CLASES_PLANTILLAS_H

namespace utec {
    template<typename TFirst, typename TSecond>
    struct pair {
        TFirst first;
        TSecond second;
    };

    class X {
        int x;
    public:
        X() { x = 20; }
    };

    class persona {
        std::string nombre;
        std::string apellido;
        int nota;
    public:
        persona() = default;

        persona(const std::string &n, const std::string &a) : nombre(n), apellido(a) {}

        template<typename ...Ts>
        persona(std::string n, std::string a, Ts ... notas): nombre(std::move(n)), apellido(std::move(a)) {
            set_promedio(notas...);
        }

        template<typename ...Ts>
        void set_promedio(Ts ...params) {
            auto total = (params+...);
            nota = total / sizeof...(params);
        }

        int get_nota() { return nota; }

        template<typename T>
        T metodo_2() {
            return T{};
        }
    };

    template<typename T>
    struct punto {
        T x;
        T y;

        punto(T x, T y) : x(x), y(y) {}

        template<typename TOther>
        punto(const punto<TOther> &other) {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
        }

        template<typename TOther>
        punto<T> &operator=(const punto<TOther> &other) {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
            return *this;
        }

    };

    template<
            typename T
            , template <typename ...> class TContainer
            >
    T sumar(TContainer<T> container) {
        T total = 0;
        for (const auto& item: container) total += item;
        return total;
    }

    template <typename T>
    struct Triangulo {
        T base;
        T altura;
        T area() { return base * altura / 2;}
    };

    template <typename T>
    struct Rectangulo {
        T base;
        T altura;
        T area() { return base * altura;}
    };

    template <typename T
            , template<typename...> class TFiguraA
            , template<typename...> class TFiguraB>
            T suma_areas(TFiguraA<T> fa, TFiguraB<T> fb) {
                return fa.area() + fb.area();
            }


}








#endif //TEMPLATE_CLASES_PLANTILLAS_H
