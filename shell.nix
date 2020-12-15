{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
  buildInputs = with pkgs; [
    cmake
    wxGTK31-gtk3
    rocm-opencl-runtime
  ];
}
