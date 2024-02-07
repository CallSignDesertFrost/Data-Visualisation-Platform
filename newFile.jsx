Vue: `` `vue
<template>
  <div id="app">
    <h1>Data Analyzing</h1>
    <pie-chart :data="chartData"></pie-chart>
  </div>
</template>

<script>
import PieChart from './components/PieChart.vue';

export default {
  name: 'App',
  components: {
    PieChart
  },
  data() {
    return {
      chartData: [
        { value: 25, name: 'Category 1' },
        { value: 50, name: 'Category 2' },
        { value: 25, name: 'Category 3' }
      ]
    };
  }
};
</script>`;
