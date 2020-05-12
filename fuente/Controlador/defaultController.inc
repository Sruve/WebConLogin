<?php

// Ejemplo de controlador para página home de la aplicación
class DefaultController
{
  public function inicio()
  {
    if (isset($_POST['registrar'])) {
      $this->registrar();
    } else if (isset($_POST['login'])) {
      $this->login();
    } else if (isset($_POST['ver'])) {
      $this->ver();
    } else if (isset($_POST['comprar'])) {
      $this->comprar();
    } else if (isset($_POST['atras'])) {
      $this->atras();
    } else if (isset($_POST['editar'])) {
      $this->editar();
    } else if (isset($_POST['confirmarCambio'])) {
      $this->confirmarCambio();
    } else if (isset($_POST['anadir'])) {
      $this->anadir();
    } else if (isset($_POST['confirmarAnadir'])) {
      $this->confirmarAnadir();
    } else if (isset($_POST['eliminar'])) {
      $this->eliminar();
    } else {
      require __DIR__ . '/../../app/plantillas/inicio.php';
    }
  }
  public function registrar()
  {
    require_once __DIR__ . '/../Modelo/Loggin.inc';
    $registro = $_POST['loggin'];
    try {
      $registroObj = new Loggin($registro);
      require_once __DIR__ . '/../Repositorio/logginRepositorio.inc';
      $comprobar = (new logginRepositorio())->comprobarUsuario($registroObj);
      if (!$comprobar) {
        $comprobar = (new logginRepositorio())->registrarUsuario($registroObj);
        if (!$comprobar) {
          $errores['mensaje'] = "Error de registro de Usuario";
        } else {
          $exito = true;
        }
      } else {
        $errores['usuario'] = "Usuario ya existente";
      }
    } catch (logginException $le) {
      $errores = $le->getErrores();
    }
    require __DIR__ . '/../../app/plantillas/inicio.php';
  }
  public function login()
  {
    require_once __DIR__ . '/../Modelo/Loggin.inc';
    $registro = $_POST['loggin'];
    try {
      $registroObj = new Loggin($registro);
      require_once __DIR__ . '/../Repositorio/logginRepositorio.inc';
      $comprobar = (new logginRepositorio())->comprobarLogin($registroObj);
      if ($comprobar != 0) {
        $rol = $comprobar;
        require_once __DIR__ . '/../Controlador/tiendaController.inc';
        $productos = (new tiendaController())->getAllProductos();
        require_once __DIR__ . '/../../app/plantillas/tienda.php';
      } else {
        $errores['errorLogin'] = "Usuario o contraseña incorrectas";
        require __DIR__ . '/../../app/plantillas/inicio.php';
      }
    } catch (logginException $le) {
      $errores = $le->getErrores();
      require __DIR__ . '/../../app/plantillas/inicio.php';
    }
  }
  public function ver()
  {
    $rol = $_POST['rol'];
    $indice = $_POST['indice'];
    require_once __DIR__ . '/../Controlador/tiendaController.inc';
    $producto = (new tiendaController())->getProducto($indice);
    require_once __DIR__ . '/../../app/plantillas/producto.php';
  }
  public function comprar()
  {
    $rol = $_POST['rol'];
    $indice = $_POST['indice'];
    $cantidad = $_POST['cantidad'];
    require_once __DIR__ . '/../Controlador/tiendaController.inc';
    $errores = (new tiendaController())->comprar($indice, $cantidad);
    if (isset($errores)) {
      require_once __DIR__ . '/../Controlador/tiendaController.inc';
      $producto = (new tiendaController())->getProducto($indice);
      require_once __DIR__ . '/../../app/plantillas/producto.php';
    } else {
      require_once __DIR__ . '/../Controlador/tiendaController.inc';
      $productos = (new tiendaController())->getAllProductos();
      require_once __DIR__ . '/../../app/plantillas/tienda.php';
    }
  }
  public function atras()
  {
    $rol = $_POST['rol'];
    require_once __DIR__ . '/../Controlador/tiendaController.inc';
    $productos = (new tiendaController())->getAllProductos();
    require_once __DIR__ . '/../../app/plantillas/tienda.php';
  }
  public function editar()
  {
    $editar = true;
    $rol = $_POST['rol'];
    $indice = $_POST['indice'];
    require_once __DIR__ . '/../Controlador/tiendaController.inc';
    $producto = (new tiendaController())->getProducto($indice);
    require_once __DIR__ . '/../../app/plantillas/producto.php';
  }
  public function confirmarCambio()
  {
    $array = $_POST["cambio"];
    $rol = $_POST['rol'];
    require_once __DIR__ . '/../Modelo/Producto.inc';
    try {
      $producto = new Producto($array);
      require_once __DIR__ . '/../Controlador/tiendaController.inc';
      (new tiendaController())->cambiarProducto($producto);
      $productos = (new tiendaController())->getAllProductos();
      require_once __DIR__ . '/../../app/plantillas/tienda.php';
    } catch (productoException $pe) {
      $errores = $pe->getErrores();
      $editar = true;
      $indice = $_POST['indice'];
      require_once __DIR__ . '/../Controlador/tiendaController.inc';
      $producto = (new tiendaController())->getProducto($indice);
      require_once __DIR__ . '/../../app/plantillas/producto.php';
    }
  }
  public function anadir()
  {
    $editar = false;
    $rol = $_POST['rol'];
    require_once __DIR__ . '/../Controlador/tiendaController.inc';
    $indice = (new tiendaController())->getLastIndice();
    require_once __DIR__ . '/../../app/plantillas/producto.php';
  }
  public function confirmarAnadir()
  {
    $array = $_POST["insertar"];
    $rol = $_POST['rol'];
    require_once __DIR__ . '/../Modelo/Producto.inc';
    try {
      $producto = new Producto($array);
      require_once __DIR__ . '/../Controlador/tiendaController.inc';
      (new tiendaController())->insertarProducto($producto);
      $producto = (new tiendaController())->getProducto($producto->getIndice());
      require_once __DIR__ . '/../../app/plantillas/producto.php';
    } catch (productoException $pe) {
      $errores = $pe->getErrores();
      $editar = false;
      $indice = $_POST['indice'];
      require_once __DIR__ . '/../../app/plantillas/producto.php';
    }
  }
  public function eliminar()
  {
    $rol = $_POST['rol'];
    $indice = $_POST['indice'];
    require_once __DIR__ . '/../Controlador/tiendaController.inc';
    $indice = (new tiendaController())->eliminar($indice);
    $productos = (new tiendaController())->getAllProductos();
    require_once __DIR__ . '/../../app/plantillas/tienda.php';
  }
}
