import javax.swing.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;
import java.sql.*;
import java.io.File;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Leer extends JFrame {
    private BufferedReader lector; //lee el archivo
    private String linea; // recibe la linea

    public Leer() {
        setSize(400, 250);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        componentes();
    }

    private void componentes() {

        JPanel panel = new JPanel();
        panel.setLayout(null);
        this.getContentPane().add(panel);

        JLabel titulo = new JLabel("Seleccione el archivo para importar");
        titulo.setBounds(100, 50, 700, 30);
        panel.add(titulo);

        JFileChooser input = new JFileChooser();

        JButton importarFile = new JButton("Seleccionar archivo");
        importarFile.setBounds(100, 100, 200, 30);
        panel.add(importarFile);


        ActionListener abrirSeleccion = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                input.showOpenDialog(null);
                File arhivoSeleccionado;
                arhivoSeleccionado = input.getSelectedFile();
                leerArchivo(String.valueOf(arhivoSeleccionado));
                JOptionPane.showMessageDialog(null, "Importado a la base de datos satisfactoriamente");
            }
        };
        importarFile.addActionListener(abrirSeleccion);
    }

    public void leerArchivo(String nombreArchivo){
        try {
            lector = new BufferedReader(new FileReader(nombreArchivo));
            while ( (linea = lector.readLine()) != null ) {
                importar(linea);
            }
            lector.close();
            linea = null;
        }catch (Exception e){
            System.out.println(e);
        }
    }

    public void importar(String fila) {
        String datos [] = fila.split(",");
        String db = "jdbc:postgresql://localhost:5432/ExamenFinal";
        try{
            Class.forName("org.postgresql.Driver");
            Connection connection = DriverManager.getConnection(db, "postgres", "secret");
            Statement createStatement = connection.createStatement();
            PreparedStatement newStatement = connection.prepareStatement("insert into inventario values (?, ?)");
            newStatement.setString(1, datos[0]);
            newStatement.setString(2, datos[1]);
            newStatement.executeQuery();
        }catch (Exception e){
            System.out.println(e);
        }
    }
}
