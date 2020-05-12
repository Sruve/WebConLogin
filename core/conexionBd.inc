<?php
require_once __DIR__ . '/../app/conf/config.inc';

class ConexionBd
{ private $con;

  public function __construct()
  { $params = (new Configuracion())->getDbParams();

    try
    { 
      $this->con = new PDO("mysql:host={$params['server']};dbname={$params['database']};port=3306", $params['user'], $params['pass']);
      $this->con->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }catch(PDOException $ex)
    { die("Error de conexión ".$ex->getMessage());
    }
  }
  public function getConexion()
  { return $this->con;
  }
}
