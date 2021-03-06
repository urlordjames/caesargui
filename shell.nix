{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = with pkgs; [
    cmake
    ninja
    wxGTK31-gtk3
    rocm-opencl-runtime
  ];
}
