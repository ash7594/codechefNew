for (i=5;i<1000000;i++) {
	var m = i/Math.sqrt(2);
	for (j=1;j<m;j++) {
		var n = Math.pow(i,2) - Math.pow(j,2);
		n = Math.sqrt(n);
		var n2 = parseInt(n);
		if (n == n2) {
			var i2 = i;
			var b = [];
			for (var k = 2;k<=Math.sqrt(i2);) {
				if (i2%k==0) {
					i2/=k;
					b.push(k);
				} else k++;
			}
			b.push(i2);
			console.log(i + " = " + b);
			break;
		}
	}
}
