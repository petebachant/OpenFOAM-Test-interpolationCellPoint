    
    // Find local flow velocity by interpolating to element location
    
    vector inflowVelocity(VGREAT, VGREAT, VGREAT);
    vector inflowVelocityPoint(0.1, 0.5, 0.2);
    label inflowCellI = mesh.findCell(inflowVelocityPoint);
    if (inflowCellI != -1)
    {
        //~ interpolationCellPoint<vector> UInterp(Uin);
        autoPtr<interpolation<vector> > UInterp = 
            interpolation<vector>::New("cellPoint", U);
        inflowVelocity = UInterp->interpolate
        (
            inflowVelocityPoint, 
            inflowCellI
        );
    }
    
    // Pick minimum value from from all processors
    reduce(inflowVelocity, minOp<vector>());
    
    Info<< "\ninflowVelocity: " << inflowVelocity << endl << endl;
