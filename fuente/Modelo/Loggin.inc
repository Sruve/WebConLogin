<?php
class Loggin
{
    private $usuario = '';
    private $contra = '';

    public function __construct(array $datos, $nuevo = true)
    {
        if ($nuevo) {
            if ($dat = $this->setUsuario($datos['usuario'])) {
                $errores['usuario'] = $dat;
            }
            if ($dat = $this->setContra($datos['contra'])) {
                $errores['contra'] = $dat;
            }
            if (isset($errores)) {
                require_once __DIR__ . '/LogginException.inc';
                throw new logginException($errores, 'Registro incorrecto');
            }
        } else {
            $this->usuario = $datos['usuario'];
            $this->contra = $datos['contra'];
        }
    }

    public function setUsuario(string $usuario)
    {
        if (empty($usuario) || !preg_match("/^([a-zA-Z]|\d|\s){3,12}$/", $usuario)) {
            return 'El nombre de usuario debe ser de entre 3 y 12 caracteres, pudiendo ser alfanumerico.';
        }
        $this->usuario = $usuario;
    }

    public function setContra(string $contra)
    {
        if (empty($contra) || !preg_match("/^([a-zA-Z]|\d|){8,100}$/", $contra)) {
            return 'La contraseña debe de ser entre 8 y 100 caracteres.';
        }
        $this->contra = $contra;
    }

    public function getUsuario(): string
    {
        return $this->usuario;
    }
    public function getContra(): string
    {
        return $this->contra;
    }
}
