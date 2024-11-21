#include <iostream>
#include "LibreriaGrafos.hpp" // <--- Libreria de grafos a utilizar 


struct Curso{
  std::string nombre_curso;
  long int codigo;
  int uv;

  bool operator <(const Curso& other) const {
    return (codigo < other.codigo); 
  }

  bool operator == (const Curso& other) const{
    return codigo == other.codigo;
  }
};

Curso curso_con_mas_uv{"", 0, 0};

void MostrarCursos (const Curso& curso);
void BuscarCursoConMasUV (const Curso& curso);

int main(int argc, char* argv[]){

  std::string curso_buscar;
  Graph<Curso> graph;

  Curso bachillerato{"Bachillerato", 0, 0 };
  Curso preca{"Precalculo", 10180, 4};
  Curso elementos{"EECT", 200087, 4};
  Curso md1{"Matematica discreta 1", 10142, 3};
  Curso funda{"Fundamentos de programacion", 190153, 4};
  Curso algebra{"Algebra vectorial y matrices", 10112, 4};
  Curso c1{"Calculo 1", 10181, 4};
  Curso PED{"PED", 190154, 4};
  Curso md2{"Matematica discret 2", 10143, 3};

  graph.add(bachillerato, preca);
  graph.add(bachillerato, elementos);
  graph.add(bachillerato, md1);
  graph.add(bachillerato, funda);
  graph.add(preca, c1);
  graph.add(preca, algebra);
  graph.add(funda, PED);
  graph.add(md1, md2);

  graph.DFS(bachillerato, MostrarCursos);
  graph.DFS(bachillerato, BuscarCursoConMasUV);
  std::cout<<"El curso con mas UVs es " << curso_con_mas_uv.nombre_curso;

  std::cout<<"\n--CURSO A BUSCAR\n---";
  std::cout << "Ingrese un nombre del curso que quiere a buscar: ";
  std::cin.ignore();  
  getline(std::cin, curso_buscar);

  if (graph.find(preca)){
      std::cout << "El curso si esta en el grafo.\n";
    }

  return 0;
}

void MostrarCursos (const Curso& curso){
  std::cout<<"\n-------------------------------------------------"<<'\n';
  std::cout<<"Curso: "<<curso.nombre_curso<<'\n';
  std::cout<<"Codigo: "<<curso.codigo<<'\n';
  std::cout<<"Unidades valorativas: "<<curso.uv<<'\n';
  std::cout<<"-------------------------------------------------"<<'\n';
}

void BuscarCursoConMasUV (const Curso& curso){

  if (curso.uv > curso_con_mas_uv.uv){
    curso_con_mas_uv = curso;
  }
  
}

