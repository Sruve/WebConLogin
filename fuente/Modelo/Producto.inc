<?php
class Producto
{
    private $indice = '';
    private $producto = '';
    private $texto = '';
    private $precio = '';
    private $cantidad = '';

    public function __construct(array $datos, $nuevo = true)
    {
        if ($nuevo) {
            if ($dat = $this->setIndice($datos['indice'])) {
                $errores['indice'] = $dat;
            }
            if ($dat = $this->setProducto($datos['producto'])) {
                $errores['producto'] = $dat;
            }
            if ($dat = $this->setTexto($datos['texto'])) {
                $errores['texto'] = $dat;
            }
            if ($dat = $this->setTextoLargo($datos['textolargo'])) {
                $errores['textolargo'] = $dat;
            }
            if ($dat = $this->setPrecio($datos['precio'])) {
                $errores['precio'] = $dat;
            }
            if ($dat = $this->setCantidad($datos['cantidad'])) {
                $errores['cantidad'] = $dat;
            }
            if ($dat = $this->setDireccion($datos['direccion'])) {
                $errores['direccion'] = $dat;
            }

            if (isset($errores)) {
                require_once __DIR__ . '/ProductoException.inc';
                throw new productoException($errores, 'Error en datos de Producto');
            }
        } else {
            $this->indice = $datos['indice'];
            $this->producto = $datos['producto'];
            $this->texto = $datos['texto'];
            $this->textolargo = $datos['textolargo'];
            $this->precio = $datos['precio'];
            $this->cantidad = $datos['cantidad'];
            $this->direccion = $datos['direccion'];
        }
    }

    public function setIndice(string $indice)
    {
        $this->indice = $indice;
    }

    public function setProducto(string $producto)
    {
        if (empty($producto) || strlen($producto)>100) {
            return "Nombre del producto debe estar relleno siendo menor de 100";
        }
        $this->producto = $producto;
    }
    public function setTextoLargo(string $textolargo)
    {
        if (strlen($textolargo)>400) {
            return "La descripcion larga debe ser menor a 400.";
        }
        $this->textolargo = $textolargo;
    }
    public function setTexto(string $texto)
    {
        if (strlen($texto)>100) {
            return "La descripcion corta debe ser menor a 100.";
        }
        $this->texto = $texto;
    }

    public function setPrecio(string $precio)
    {
        if (empty($precio) || $precio <= 0) {
            return "Precio debe ser mayor a 0.";
        }
        $this->precio = $precio;
    }
    public function setCantidad(string $cantidad)
    {
        if (empty($cantidad) || $cantidad == 0) {
            return "Cantidad debe ser mayor a 0.";
        }
        $this->cantidad = $cantidad;
    }
    public function setDireccion(string $direccion)
    {
        if (!empty($direccion) && strlen($direccion) > 4) {
            $this->direccion = $direccion;
        } else {
            $this->direccion = "null";
        }
    }
    public function getIndice(): string
    {
        return $this->indice;
    }
    public function getDireccion(): string
    {
        return $this->direccion;
    }
    public function getProducto(): string
    {
        return $this->producto;
    }
    public function getTexto(): string
    {
        return $this->texto;
    }
    public function getTextoLargo(): string
    {
        return $this->textolargo;
    }
    public function getPrecio(): string
    {
        return $this->precio;
    }
    public function getCantidad(): string
    {
        return $this->cantidad;
    }
}
