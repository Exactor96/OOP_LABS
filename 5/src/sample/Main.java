package sample;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Menu;
import javafx.scene.control.MenuBar;
import javafx.scene.control.MenuItem;
import javafx.scene.layout.VBox;
import javafx.scene.web.HTMLEditor;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        //Menu toolbar
        MenuBar menu = new MenuBar();
        Menu menuFile = new Menu("File");

        MenuItem menuItemNew = new MenuItem("New");
        MenuItem menuItemOpen = new MenuItem("Open");
        MenuItem menuItemOpenDB = new MenuItem("Open from DB");

        MenuItem menuItemLoad = new MenuItem("Load");
        MenuItem menuItemLoadDB = new MenuItem("Load from DB");

        MenuItem menuItemSave = new MenuItem("Save");
        MenuItem menuItemSaveDB = new MenuItem("Save to DB");

        

        menuFile.getItems().addAll(
                menuItemNew,
                menuItemOpen,
              //  menuItemOpenDB,
                //menuItemLoad,
               // menuItemLoadDB,
                menuItemSave
                //menuItemSaveDB
        );
        menu.getMenus().add(menuFile);

        HTMLEditor editor = new HTMLEditor();
        editor.setPrefHeight(300);
        editor.setPrefWidth(500);
        VBox root = new VBox();

        root.getChildren().add(menu);
        root.getChildren().add(editor);
        menuItemOpen.setOnAction((ActionEvent  arg0) -> {
            FileChooser fileChooser = new FileChooser();
            FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("HTML files (*.html)", "*.html");
            fileChooser.getExtensionFilters().add(extFilter);

            File file = fileChooser.showOpenDialog(primaryStage);

            if (file != null) {
                editor.setHtmlText(readFile(file));
            }
            System.out.println("Opening");
        });
        menuItemSave.setOnAction((ActionEvent arg0) -> {
            FileChooser fileChooser = new FileChooser();
            //Set extension filter for text files
            FileChooser.ExtensionFilter extFilter = new FileChooser.ExtensionFilter("HTML files (*.html)", "*.html");
            fileChooser.getExtensionFilters().add(extFilter);

            //Show save file dialog
            File file = fileChooser.showSaveDialog(primaryStage);

            if (file != null) {
                saveTextToFile(editor.getHtmlText(), file);
            }
            System.out.println("saving");
        });

        menuItemNew.setOnAction((ActionEvent arg0) ->{
            editor.setHtmlText("");

        });
        primaryStage.setScene(new Scene(root));
        primaryStage.setTitle("NoteBook");
        primaryStage.show();


        primaryStage.show();
    }

    private void saveTextToFile(String content, File file) {
        try {
            PrintWriter writer;
            writer = new PrintWriter(file);
            writer.println(content);
            writer.close();
        } catch (IOException ex) {
            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private String readFile(File file){
        StringBuilder stringBuffer = new StringBuilder();
        BufferedReader bufferedReader = null;


        try {
            bufferedReader = new BufferedReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        String text = "";
            while (true) {
                try {
                    if (!((text = bufferedReader.readLine()) != null)) break;
                } catch (IOException e) {
                    e.printStackTrace();
                }
                stringBuffer.append(text);
            }




        return stringBuffer.toString();
    }
    public static void main(String[] args) {
        launch(args);
    }
}
