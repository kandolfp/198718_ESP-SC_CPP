// src/eigen_cholmod.cpp
#include <iostream>
#include <Eigen/Sparse>
#include <Eigen/CholmodSupport> // requires CHOLMOD installed

int main() {
  using SpMat = Eigen::SparseMatrix<double>;
  SpMat A(3,3);
  A.insert(0,0)=4; A.insert(0,1)=-1;
  A.insert(1,0)=-1; A.insert(1,1)=4; A.insert(1,2)=-1;
  A.insert(2,1)=-1; A.insert(2,2)=3;
  Eigen::Vector3d b(1,2,3);

  Eigen::CholmodSimplicialLDLT<SpMat> solver;
  solver.compute(A);
  if(solver.info()!=Eigen::Success) {
    std::cerr << "Factorization failed\n";
    return 1;
  }
  Eigen::Vector3d x = solver.solve(b);
  std::cout << "x = " << x.transpose() << "\n";
  return 0;
}