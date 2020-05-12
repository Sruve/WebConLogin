<?php
class logginRepositorio
{

  public function comprobarUsuario($registroObj): bool
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "SELECT usuario FROM Usuarios WHERE usuario=:usuarioObj";
      $snt = $con->prepare($sql);
      $snt->bindValue(':usuarioObj', $registroObj->getUsuario());
      $snt->execute();
      $usuario = $snt->fetchAll(\PDO::FETCH_ASSOC);
      if (count($usuario)) {
        return true;
      } else {
        return false;
      }
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function registrarUsuario($registroObj): bool
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "INSERT INTO Usuarios (Usuario, Contrasena,Rol) values (:usuarioObj, :contrasenaObj,:rolObj)";
      $snt = $con->prepare($sql);
      $snt->bindValue(':usuarioObj', $registroObj->getUsuario());
      $snt->bindValue(':contrasenaObj', $registroObj->getContra());
      $snt->bindValue(':rolObj', 2);
      $snt->execute();
      return true;
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
  public function comprobarLogin($registroObj): int
  {
    require_once __DIR__ . '/../../core/conexionBd.inc';
    try {
      $con = (new ConexionBd())->getConexion();
      $sql = "SELECT Rol FROM Usuarios WHERE usuario=:usuarioObj and contrasena=:contrasenaObj";
      $snt = $con->prepare($sql);
      $snt->bindValue(':usuarioObj', $registroObj->getUsuario());
      $snt->bindValue(':contrasenaObj', $registroObj->getContra());
      $snt->execute();
      $usuario = $snt->fetchAll(\PDO::FETCH_ASSOC);
      if (count($usuario)) {
        return $usuario[0]['Rol'];
      } else {
        return 0;
      }
    } catch (\PDOException $ex) {
      throw $ex;
    } finally {
      $snt = null;
      $con = null;
    }
  }
}
