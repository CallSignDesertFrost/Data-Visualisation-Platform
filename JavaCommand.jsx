@Override
public void start(Stage primaryStage) {
    PieChart chart = new PieChart();
    chart.setTitle("Data Analysis");

    // Add data to the chart
    chart.getData().add(new PieChart.Data("Category 1", 25));
    chart.getData().add(new PieChart.Data("Category 2", 50));
    chart.getData().add(new PieChart.Data("Category 3", 25));

    primaryStage.setScene(new Scene(chart, 800, 600));
    primaryStage.show();
}

public static void main(String[] args) {
    launch(args);
}