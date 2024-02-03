#include <iostream>
#include <vector>
#include <algorithm> // Para la función std::sort

// Definición de la estructura Solicitud
struct Solicitud {
    int id;
    std::string origen;
    std::string destino;
    std::string usuario;
    int numeroContagios;
    bool esVulnerable;
    int edad;
    char sexo;
    int numeroQuejas;
};

// Contador para asignar IDs automáticamente
int idUsuario = 1;

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
            std::cout<< "\n\tID: " << solicitud.id << "\n\tOrigen: " << solicitud.origen << "\n\tDestino: " << solicitud.destino
                    << "\n\tUsuario: " << solicitud.usuario << "\n\tEdad: " << solicitud.edad << "\n\tSexo: " << solicitud.sexo
                    << "\n\tQuejas: " << solicitud.numeroQuejas << "\n\tContagios: " << solicitud.numeroContagios;
                    if (solicitud.esVulnerable) {
    					std::cout << "\n\t(Usuario vulnerable)";
					}
					std::cout << std::endl;
                      
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
                          << ", Quejas: " << solicitud.numeroQuejas << ", Contagios: " << solicitud.numeroContagios;
                    	  if (solicitud.esVulnerable) {
    							std::cout << "\n\t(Usuario vulnerable)";
							}
						  std::cout << std::endl;
            }
        }
        if (!encontrado) {
            std::cout << "\n\t\tNo se encontró una solicitud con el nombre de usuario especificado." << std::endl;
        }
    }

    // Método para mostrar todas las solicitudes en orden alfabético por nombre de usuario
    void mostrarSolicitudesOrdenadasPorNombre() {
        std::vector<Solicitud> solicitudesOrdenadas = solicitudes;
        std::sort(solicitudesOrdenadas.begin(), solicitudesOrdenadas.end(), [](const Solicitud& a, const Solicitud& b) {
            return a.usuario < b.usuario;
        });

        std::cout << "\n\t\tSolicitudes ordenadas por nombre de usuario:" << std::endl;
        for (const Solicitud& solicitud : solicitudesOrdenadas) {
            std::cout << "\n\tID: " << solicitud.id << "\n\tOrigen: " << solicitud.origen << "\n\tDestino: " << solicitud.destino
                      << "\n\tUsuario: " << solicitud.usuario << "\n\tEdad: " << solicitud.edad << "\n\tSexo: " << solicitud.sexo
                      << "\n\tQuejas: " << solicitud.numeroQuejas << "\n\tContagios: " << solicitud.numeroContagios;
                    if (solicitud.esVulnerable) {
    					std::cout << "\n\t(Usuario vulnerable)";
					}
					std::cout << std::endl;
        }
    }

    // Método para mostrar una lista de usuarios ordenados de mayor a menor cantidad de quejas
    void mostrarUsuariosPorQuejas() {
        std::vector<Solicitud> usuariosOrdenadosPorQuejas = solicitudes;
        std::sort(usuariosOrdenadosPorQuejas.begin(), usuariosOrdenadosPorQuejas.end(), [](const Solicitud& a, const Solicitud& b) {
            return a.numeroQuejas > b.numeroQuejas;
        });

        std::cout << "\n\t\tUsuarios ordenados por cantidad de quejas (de mayor a menor):" << std::endl;
        for (const Solicitud& solicitud : usuariosOrdenadosPorQuejas) {
            std::cout << "\n\tUsuario: " << solicitud.usuario << ", Quejas: " << solicitud.numeroQuejas << std::endl;
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
                    std::cout << "\n\tUsuario eliminado debido a quejas excesivas." << std::endl;
                }
                return true; // Solicitud encontrada y número de quejas modificado
            }
        }
        return false; // Solicitud no encontrada
    }
};

int main() {
	
    ListaSolicitudes listaSolicitudes;
    
	Solicitud solicitud;
	
    while (true) {
        
        // Asignar automáticamente un ID numérico
        solicitud.id = ListaSolicitudes::asignarIdUsuario();
        system("cls");
		std::cout << "\n\t\tIngrese la solicitud de viaje:" << std::endl;
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
        std::cout << "\n\tNúmero de contagios por COVID-19: ";
		std::cin >> solicitud.numeroContagios;
		solicitud.esVulnerable = (solicitud.numeroContagios >= 5);

        listaSolicitudes.agregarSolicitud(solicitud);
		
		system("cls");
        std::cout << "\n\t\tLista de solicitudes actualizada:" << std::endl;
        listaSolicitudes.mostrarSolicitudes();

        char respuesta;
        std::cout << "\n\t¿Desea agregar otra solicitud? (s/n): ";
        std::cin >> respuesta;

        if (respuesta != 's' && respuesta != 'S') {
            break;
        }
    }

    // Solicitar al usuario el ID del usuario para modificar el número de quejas
    int idModificar, nuevoNumeroQuejas;
    std::cout << "\n\tIngrese el ID del usuario para modificar el número de quejas: ";
    std::cin >> idModificar;
    std::cout << "\n\tIngrese el nuevo número de quejas: ";
    std::cin >> nuevoNumeroQuejas;
    std::cout << "\n\tNúmero de contagios por COVID-19: ";
	std::cin >> solicitud.numeroContagios;
	// Etiquetar como usuario vulnerable si tiene 5 o más contagios
	solicitud.esVulnerable = (solicitud.numeroContagios >= 1);

    if (listaSolicitudes.modificarNumeroQuejasPorId(idModificar, nuevoNumeroQuejas)) {
        std::cout << "Número de quejas modificado con éxito." << std::endl;
    } else {
        std::cout << "No se encontró una solicitud con el ID especificado." << std::endl;
    }

    // Mostrar todas las solicitudes ordenadas por nombre de usuario
    listaSolicitudes.mostrarSolicitudesOrdenadasPorNombre();

    // Mostrar usuarios ordenados por cantidad de quejas
    listaSolicitudes.mostrarUsuariosPorQuejas();

    return 0;
}




