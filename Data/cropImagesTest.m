folder = 'data/test-set/';
load('cars_test_annos.mat');
for i = 1:size(annotations, 2)
    bb = [annotations(i).bbox_x1, annotations(i).bbox_y1, ...
        annotations(i).bbox_x2, annotations(i).bbox_y2];
    imageName = [folder annotations(i).fname];
    image = imread(imageName);
    height = size(image, 1);
    width = size(image, 2);
    bb_width = bb(3) - bb(1);
    bb_height = bb(4) - bb(2);
    imageName = [folder 'crop/' annotations(i).fname];
    imwrite(imcrop(image, [bb(1), bb(2), bb_width, bb_height]), imageName);
    x10 = max([0, bb(1) - bb_width*.1]);
    y10 = max([0, bb(2) - bb_height*.1]);
    width10 = min([width, bb(3) + bb_width*.1]) - x10;
    height10 = min([height, bb(4) + bb_height*.1]) - y10;
    imageName = [folder 'crop10/' annotations(i).fname];
    imwrite(imcrop(image, [x10, y10, width10, height10]), imageName); 
    x20 = max([0, bb(1) - bb_width*.2]);
    y20 = max([0, bb(2) - bb_height*.2]);
    width20 = min([width, bb(3) + bb_width*.2]) - x20;
    height20 = min([height, bb(4) + bb_height*.2]) - y20;
    imageName = [folder 'crop20/' annotations(i).fname];
    imwrite(imcrop(image, [x20, y20, width20, height20]), imageName); 
end