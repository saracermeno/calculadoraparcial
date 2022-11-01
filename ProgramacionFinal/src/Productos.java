import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Productos extends JFrame {
    public Productos() {
        setSize(620, 400);
        setTitle("Proyecto Final Programacion");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        componentes();
    }

    private void componentes() {
        JPanel panel = new JPanel();
        panel.setLayout(null);
        this.getContentPane().add(panel);

        JLabel nombre = new JLabel("Escriba un nombre:");
        nombre.setBounds(200, 50, 700, 30);
        panel.add(nombre);

        JLabel codigo = new JLabel("Escriba el codigo de producto:");
        codigo.setBounds(200, 120, 700, 30);
        panel.add(codigo);
        JButton guardar = new JButton("Guardar");
        guardar.setBounds(200, 200, 200, 30);
        panel.add(guardar);
        JButton exportar = new JButton("Exportar");
        exportar.setBounds(200, 240, 200, 30);
        panel.add(exportar);
        JTextField escribirNombre = new JTextField();
        escribirNombre.setBounds(200, 85, 200, 30);
        panel.add(escribirNombre);
        JTextField escribirCodigo = new JTextField();
        escribirCodigo.setBounds(200, 155, 200, 30);
        panel.add(escribirCodigo);

        ActionListener nuevoProducto = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Conexion conexion = new Conexion();
                conexion.agregarProducto(escribirNombre.getText(), escribirCodigo.getText());
                JOptionPane.showMessageDialog(null, "Se guardó en la base de datos");
            }
        };
        guardar.addActionListener(nuevoProducto);

        ActionListener crearArchivo = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Conexion conexion = new Conexion();
                conexion.exportarTXT();
                JOptionPane.showMessageDialog(null, "Se exportó el archivo");
            }
        };

        exportar.addActionListener(crearArchivo);
    }
}

