leftOffset = 10;
bottomOffset = 11.5;
switchWidth = 24;
switchHeight = 18;
switchVgap = 6;
switchHgap = 6;
holeRadius = 16.5/2;

module hole(row, column) {
    /* Rectangular Holes
    xLoc = leftOffset + (row * (switchWidth + switchHgap));
    yLoc = bottomOffset + (column * (switchHeight + switchVgap));
    translate ([xLoc, yLoc, -2]) cube([switchWidth, switchHeight, 6]);
    */
    /* Round Holes */
    xLoc = leftOffset + (row * (switchWidth + switchHgap)) + (switchWidth / 2);
    yLoc = bottomOffset + (column * (switchHeight + switchVgap)) + (switchHeight / 2);
    translate ([xLoc, yLoc, -2]) cylinder(6, holeRadius, holeRadius, false);
    
}

difference() {
    /* cube([482.6, 44.5*2, 3.175]);  /* Full width */
    /* cube([482.6/2, 44.5*2, 3.175]);  /* Half Width */
    cube([40, 40, 3.175]);  /* Test Print */
    hole(0, 0);
    /*
    hole(0, 1);
    hole(0, 2);
    hole(1, 0);
    hole(1, 1);
    hole(1, 2);
    hole(2, 0);
    hole(2, 1);
    hole(2, 2);
    hole(3, 0);
    hole(3, 1);
    hole(3, 2);
    hole(5, 0);
    hole(5, 1);
    hole(5, 2);
    hole(6, 0);
    hole(6, 1);
    hole(6, 2);
    */
}