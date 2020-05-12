<?php

class TiendaController
{
  public function getProducto($indice)
  {
    require_once __DIR__ . '/../Repositorio/tiendaRepositorio.inc';
    return (new tiendaRepositorio())->getProducto($indice);
  }
  public function getAllProductos()
  {
    require_once __DIR__ . '/../Repositorio/tiendaRepositorio.inc';
    return (new tiendaRepositorio())->cargarProductos();
  }

  public function comprar($indice, $cantidad)
  {
    require_once __DIR__ . '/../Repositorio/tiendaRepositorio.inc';
    $cantidadMaxima = (new tiendaRepositorio())->getCantidad($indice);
    if ($cantidad > 0) {
      if ($cantidad <= $cantidadMaxima) {
        (new tiendaRepositorio())->comprarProducto($indice, $cantidad);
        $compraExitosa = true;
        $productos = (new tiendaRepositorio())->cargarProductos();
      } else {
        $errores['Cantidad'] = "Existencias insuficientes";
        return $errores;
      }
    } else {
      $errores['Cantidad'] = "Cantidad debe ser mayor a 0.";
      return $errores;
    }
  }

  public function cambiarProducto($producto)
  {
    require_once __DIR__ . '/../Repositorio/tiendaRepositorio.inc';
    (new tiendaRepositorio())->cambiarProducto($producto);
  }
  public function getLastIndice()
  {
    require_once __DIR__ . '/../Repositorio/tiendaRepositorio.inc';
    return (new tiendaRepositorio())->getLastIndice();
  }
  public function insertarProducto($producto)
  {
    require_once __DIR__ . '/../Repositorio/tiendaRepositorio.inc';
    (new tiendaRepositorio())->insertarProducto($producto);
  }
  public function eliminar($indice)
  {
    require_once __DIR__ . '/../Repositorio/tiendaRepositorio.inc';
    (new tiendaRepositorio())->eliminar($indice);
  }
}
