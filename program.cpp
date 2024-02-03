#include <iostream>
#include <vector>
#include <algorithm> // Para la función std::sort

// Definición de la estructura Solicitud
struct Solicitud {
    int id;
    std::string origen;
    std::string destino;
    std::string usuario;
    int edad;
    char sexo;
    int numeroQuejas;
};

// Contador para asignar IDs automáticamente
int idUsuario = 1;

// Prototipos de funciones
//void mostrarMenu();
//void agregarSolicitud(ListaSolicitudes & listaSolicitudes);
//void mostrarTodasLasSolicitudes(ListaSolicitudes& listaSolicitudes);
//void buscarSolicitudPorNombre(ListaSolicitudes& listaSolicitudes);
//void mostrarSolicitudesOrdenadasPorNombre(ListaSolicitudes& listaSolicitudes);
//void modificarNumeroQuejas(ListaSolicitudes& listaSolicitudes);
//void mostrarUsuariosPorQuejas(ListaSolicitudes& listaSolicitudes);

// Definición de la clase ListaSolicitudes
class ListaSolicitudes {
private:
    std::vector<Solicitud> solicitudes;

public:
    // Método para agregar una solicitud a la lista
    void agregarSolicitud(const Solicitud& solicitud) {
        solicitudes.push_back(solicitud);
    }

    // Método para mostrar todas las solicitudes en la lista
    void mostrarSolicitudes() const {
        for (const Solicitud& solicitud : solicitudes) {
            std::cout << "ID: " << solicitud.id << ", Origen: " << solicitud.origen << ", Destino: " << solicitud.destino
                      << ", Usuario: " << solicitud.usuario << ", Edad: " << solicitud.edad << ", Sexo: " << solicitud.sexo
                      << ", Quejas: " << solicitud.numeroQuejas << std::endl;
        }
    }

    // Método para eliminar una solicitud por ID de usuario
    bool eliminarSolicitudPorId(int idUsuario) {
        for (auto it = solicitudes.begin(); it != solicitudes.end(); ++it) {
            if (it->id == idUsuario) {
                solicitudes.erase(it);
                return true; // Solicitud encontrada y eliminada
            }
        }
        return false; // Solicitud no encontrada
    }

    // Método para buscar una solicitud por el nombre de usuario
    void buscarSolicitudPorNombre(const std::string& nombreUsuario) const {
        bool encontrado = false;
        for (const Solicitud& solicitud : solicitudes) {
            if (solicitud.usuario == nombreUsuario) {
                encontrado = true;
                std::cout << "Solicitud encontrada:" << std::endl;
                std::cout << "ID: " << solicitud.id << ", Origen: " << solicitud.origen << ", Destino: " << solicitud.destino
                          << ", Usuario: " << solicitud.usuario << ", Edad: " << solicitud.edad << ", Sexo: " << solicitud.sexo
                          << ", Quejas: " << solicitud.numeroQuejas << std::endl;
            }
        }
        if (!encontrado) {
            std::cout << "No se encontró una solicitud con el nombre de usuario especificado." << std::endl;
        }
    }

    // Método para mostrar todas las solicitudes en orden alfabético por nombre de usuario
    void mostrarSolicitudesOrdenadasPorNombre() {
        std::vector<Solicitud> solicitudesOrdenadas = solicitudes;
        std::sort(solicitudesOrdenadas.begin(), solicitudesOrdenadas.end(), [](const Solicitud& a, const Solicitud& b) {
            return a.usuario < b.usuario;
        });

        std::cout << "Solicitudes ordenadas por nombre de usuario:" << std::endl;
        for (const Solicitud& solicitud : solicitudesOrdenadas) {
            std::cout << "ID: " << solicitud.id << ", Origen: " << solicitud.origen << ", Destino: " << solicitud.destino
                      << ", Usuario: " << solicitud.usuario << ", Edad: " << solicitud.edad << ", Sexo: " << solicitud.sexo
                      << ", Quejas: " << solicitud.numeroQuejas << std::endl;
        }
    }

    // Método para mostrar una lista de usuarios ordenados de mayor a menor cantidad de quejas
    void mostrarUsuariosPorQuejas() {
        std::vector<Solicitud> usuariosOrdenadosPorQuejas = solicitudes;
        std::sort(usuariosOrdenadosPorQuejas.begin(), usuariosOrdenadosPorQuejas.end(), [](const Solicitud& a, const Solicitud& b) {
            return a.numeroQuejas > b.numeroQuejas;
        });

        std::cout << "Usuarios ordenados por cantidad de quejas (de mayor a menor):" << std::endl;
        for (const Solicitud& solicitud : usuariosOrdenadosPorQuejas) {
            std::cout << "Usuario: " << solicitud.usuario << ", Quejas: " << solicitud.numeroQuejas << std::endl;
        }
    }

    // Método para asignar automáticamente un ID numérico a una solicitud
    static int asignarIdUsuario() {
        return idUsuario++;
    }

    // Método para modificar el número de quejas de un usuario por su ID
    bool modificarNumeroQuejasPorId(int idUsuario, int nuevoNumeroQuejas) {
        for (auto& solicitud : solicitudes) {
            if (solicitud.id == idUsuario) {
                solicitud.numeroQuejas = nuevoNumeroQuejas;
                if (nuevoNumeroQuejas >= 5) {
                    eliminarSolicitudPorId(idUsuario);
                    std::cout << "Usuario eliminado debido a quejas excesivas." << std::endl;
                }
                return true; // Solicitud encontrada y número de quejas modificado
            }
        }
        return false; // Solicitud no encontrada
    }
};

// Función para mostrar el menú
void mostrarMenu() {
	system("cls");
    std::cout << "\n\t\t\t--- Menú ---" << std::endl;
    std::cout << "\n\t1. Agregar solicitud de viaje" << std::endl;
    std::cout << "\t2. Mostrar todas las solicitudes" << std::endl;
    std::cout << "\t3. Buscar solicitud por nombre de usuario" << std::endl;
    std::cout << "\t4. Mostrar solicitudes ordenadas por nombre de usuario" << std::endl;
    std::cout << "\t5. Modificar número de quejas de un usuario" << std::endl;
    std::cout << "\t6. Mostrar usuarios ordenados por cantidad de quejas" << std::endl;
    std::cout << "\t7. Salir" << std::endl;
    std::cout << "\n\tIngrese el número de la opción deseada: ";
}

// Función para agregar una solicitud
void agregarSolicitud(ListaSolicitudes& listaSolicitudes) {
	system("cls");
    std::cout << "\n\t\tIngrese la solicitud de viaje:" << std::endl;
    Solicitud solicitud;

    // Asignar automáticamente un ID numérico
    solicitud.id = ListaSolicitudes::asignarIdUsuario();

    std::cout << "\n\tOrigen: ";
    std::cin >> solicitud.origen;
    std::cout << "\n\tDestino: ";
    std::cin >> solicitud.destino;
    std::cout << "\n\tUsuario: ";
    std::cin >> solicitud.usuario;
    std::cout << "\n\tEdad: ";
    std::cin >> solicitud.edad;
    std::cout << "\n\tSexo (M/F): ";
    std::cin >> solicitud.sexo;
    std::cout << "\n\tNúmero de quejas: ";
    std::cin >> solicitud.numeroQuejas;

    listaSolicitudes.agregarSolicitud(solicitud);

    std::cout << "\n\t\tSolicitud agregada con éxito." << std::endl;
}

// Función para mostrar todas las solicitudes
void mostrarTodasLasSolicitudes(ListaSolicitudes& listaSolicitudes) {
    std::cout << "Lista de todas las solicitudes:" << std::endl;
    listaSolicitudes.mostrarSolicitudes();
}

// Función para buscar una solicitud por nombre de usuario
void buscarSolicitudPorNombre(ListaSolicitudes& listaSolicitudes) {
    std::string nombreBuscar;
    std::cout << "Ingrese el nombre del usuario que desea buscar: ";
    std::cin >> nombreBuscar;

    listaSolicitudes.buscarSolicitudPorNombre(nombreBuscar);
}

// Función para mostrar solicitudes ordenadas por nombre de usuario
void mostrarSolicitudesOrdenadasPorNombre(ListaSolicitudes& listaSolicitudes) {
    listaSolicitudes.mostrarSolicitudesOrdenadasPorNombre();
}

// Función para modificar el número de quejas de un usuario
void modificarNumeroQuejas(ListaSolicitudes& listaSolicitudes) {
    int idModificar, nuevoNumeroQuejas;
    std::cout << "Ingrese el ID del usuario para modificar el número de quejas: ";
    std::cin >> idModificar;
    std::cout << "Ingrese el nuevo número de quejas: ";
    std::cin >> nuevoNumeroQuejas;

    if (listaSolicitudes.modificarNumeroQuejasPorId(idModificar, nuevoNumeroQuejas)) {
        std::cout << "Número de quejas modificado con éxito." << std::endl;
    } else {
        std::cout << "No se encontró una solicitud con el ID especificado." << std::endl;
    }
}

// Función para mostrar usuarios ordenados por cantidad de quejas
void mostrarUsuariosPorQuejas(ListaSolicitudes& listaSolicitudes) {
    listaSolicitudes.mostrarUsuariosPorQuejas();
}

int main() {
    ListaSolicitudes listaSolicitudes;

    while (true) {
        mostrarMenu();
        char opcion;
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar el buffer del teclado

        switch (opcion) {
            case '1':
                agregarSolicitud(listaSolicitudes);
                break;
            case '2':
                mostrarTodasLasSolicitudes(listaSolicitudes);
                break;
            case '3':
                buscarSolicitudPorNombre(listaSolicitudes);
                break;
            case '4':
                mostrarSolicitudesOrdenadasPorNombre(listaSolicitudes);
                break;
            case '5':
                modificarNumeroQuejas(listaSolicitudes);
                break;
            case '6':
                mostrarUsuariosPorQuejas(listaSolicitudes);
                break;
            case '7':
                std::cout << "Saliendo del programa..." << std::endl;
                return 0;
            default:
                std::cout << "Opción no válida. Por favor, seleccione una opción válida." << std::endl;
                break;
        }
    }
}
