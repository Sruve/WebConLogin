<?php
class configuracion
{ private $dbParams = []; 

  public function __construct()
  { $this->dbParams = ["server"=>"localhost", 
                       "database"=>"webconlogin", 
                       "user"=>"admin", 
                       "pass"=>"admin", 
                       "charset"=>"utf-8"]; 
  }

  public function getDbParams(): Array
  { return $this->dbParams;
  }
}
