<?php

require_once 'BangunDatar.php';

class Lingkaran extends BangunDatar {
    private $jari;

    public function __construct($jari) {
        $this->jari = $jari;
    }

    public function hitungLuas() {
        return M_PI * $this->jari * $this->jari;
    }

    public function hitungKeliling() {
        return 2 * M_PI * $this->jari;
    }
}

?>
