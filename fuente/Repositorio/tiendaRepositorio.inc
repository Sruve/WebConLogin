<?php
class tiendaRepositorio
{

  public function cargarProductos(): array
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "SELECT * FROM Productos";
      $snt = $con->prepare($sql);
      $snt->execute();
      $productos = $snt->fetchAll(\PDO::FETCH_ASSOC);
      return $productos;
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function getProducto($indice): array
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "SELECT * FROM Productos where indice =:eIndice";
      $snt = $con->prepare($sql);
      $snt->bindValue(':eIndice', $indice);
      $snt->execute();
      $producto = $snt->fetchAll(\PDO::FETCH_ASSOC);
      return $producto;
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function getCantidad($indice): int
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "SELECT Cantidad FROM Productos where indice =:eIndice";
      $snt = $con->prepare($sql);
      $snt->bindValue(':eIndice', $indice);
      $snt->execute();
      $cantidad = $snt->fetchAll(\PDO::FETCH_ASSOC);
      return $cantidad[0]['Cantidad'];
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function comprarProducto($indice, $cantidad): bool
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "SELECT cantidad FROM Productos where indice =:eIndice";
      $snt = $con->prepare($sql);
      $snt->bindValue(':eIndice', $indice);
      $snt->execute();
      $cantidadBD = $snt->fetch(\PDO::FETCH_ASSOC);
      $cantidadBD = $cantidadBD['cantidad'];
      $cantidad = $cantidadBD - $cantidad;
      $sql = "UPDATE Productos set cantidad=:eCantidad where indice =:eIndice";
      $snt = $con->prepare($sql);
      $snt->bindValue(':eCantidad', $cantidad);
      $snt->bindValue(':eIndice', $indice);
      $snt->execute();
      return true;
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function cambiarProducto($producto): bool
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      if ($producto->getDireccion()!="null") {
        $sql = "UPDATE Productos set producto=:eProducto, texto=:eTexto,textolargo=:eTextoLargo, cantidad=:eCantidad, precio=:ePrecio,direccion=:eDireccion where indice =:eIndice";
        $snt = $con->prepare($sql);
        $snt->bindValue(':eDireccion', $producto->getDireccion());
      } else {
        $sql = "UPDATE Productos set producto=:eProducto, texto=:eTexto,textolargo=:eTextoLargo, cantidad=:eCantidad, precio=:ePrecio where indice =:eIndice";
        $snt = $con->prepare($sql);
      }      
      $snt->bindValue(':eProducto', $producto->getProducto());
      $snt->bindValue(':eTexto', $producto->getTexto());
      $snt->bindValue(':eTextoLargo', $producto->getTextoLargo());
      $snt->bindValue(':eCantidad', $producto->getCantidad());
      $snt->bindValue(':ePrecio', $producto->getPrecio());
      $snt->bindValue(':eIndice', $producto->getIndice());
      $snt->execute();
      return true;
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function getLastIndice(): Int
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "SELECT MAX(Indice) FROM Productos";
      $snt = $con->prepare($sql);
      $snt->execute();
      $indice = $snt->fetch(\PDO::FETCH_ASSOC);
      $indice = (int)$indice['MAX(Indice)'];
      $indice++;
      return $indice;
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function insertarProducto($producto): bool
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "INSERT INTO Productos (Indice,Producto,Texto,TextoLargo,Cantidad,Precio,Direccion) VALUES (:eIndice,:eProducto, :eTexto, :eTextoLargo, :eCantidad, :ePrecio, :eDireccion)";
      $snt = $con->prepare($sql);
      $snt->bindValue(':eProducto', $producto->getProducto());
      $snt->bindValue(':eTexto', $producto->getTexto());
      $snt->bindValue(':eTextoLargo', $producto->getTextoLargo());
      $snt->bindValue(':eCantidad', $producto->getCantidad());
      $snt->bindValue(':ePrecio', $producto->getPrecio());
      $snt->bindValue(':eIndice', $producto->getIndice());
      $snt->bindValue(':eDireccion', $producto->getDireccion());
      $snt->execute();
      return true;
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function eliminar($indice): bool
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "DELETE FROM Productos where Indice =:eIndice";
      $snt = $con->prepare($sql);
      $snt->bindValue(':eIndice', $indice);
      $snt->execute();
      return true;
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function carrousel(){

  }
}
