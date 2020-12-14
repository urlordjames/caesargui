{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = with pkgs; [
    cmake
    wxGTK31
    rocm-opencl-runtime
  ];
}
