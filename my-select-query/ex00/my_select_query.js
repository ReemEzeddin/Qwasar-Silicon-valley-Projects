class MySelectQuery {
  constructor(contain) {
    this.contain = contain;
  }

    where(column_name, criteria) {

        var arr = this.contain.split("\n");
        var i = 0;
        var elem;
        var row ;
        var key = -1;
        var result = [];
        var x = 0;
        row = arr.length;
        elem = arr[0].split(",", row);
        row = elem.length;
        for(; i < elem.length; i++ )
        {
            if(0 == elem[i].localeCompare(column_name))
                {
                    key = i;
                    break;
                }
        }
        i = 1;
        for(; i < row; i++ )
        {
            elem = arr[i].split(",", 10);
            if (0 == elem[key].localeCompare(criteria))
            {
                result[x] = arr[i];
                x++;
            }
        }
        return (result);
  }
}