new_dir = dir('data/new-set');
new_bb = csvread('data/new-set/test_boundingboxes.csv');
img = 1;
for i = 1:size(new_dir, 1)
    if and(isempty(strfind(new_dir(i).name, '.jpg')), ...
        isempty(strfind(new_dir(i).name, '.png')))
        continue
    end
    bb = new_bb(img, :);
    imageName = ['data/new-set/' new_dir(i).name];
    image = imread(imageName);
    height = size(image, 1);
    width = size(image, 2);
%     figure
%     imshow(image)
%     hold on;
%     plot(bb(1), bb(2), 'r*')
%     hold on;
%     plot(bb(3), bb(4), 'r*')
    bb_width = bb(3) - bb(1);
    bb_height = bb(4) - bb(2);
    imageName = ['data/new-set/crop/' sprintf('%04d', img) '.png'];
    imwrite(imcrop(image, [bb(1), bb(2), bb_width, bb_height]), imageName);
    x10 = max([0, bb(1) - bb_width*.1]);
    y10 = max([0, bb(2) - bb_height*.1]);
    width10 = min([width, bb(3) + bb_width*.1]) - x10;
    height10 = min([height, bb(4) + bb_height*.1]) - y10;
    imageName = ['data/new-set/crop10/' sprintf('%04d', img) '.png'];
    imwrite(imcrop(image, [x10, y10, width10, height10]), imageName); 
    x20 = max([0, bb(1) - bb_width*.2]);
    y20 = max([0, bb(2) - bb_height*.2]);
    width20 = min([width, bb(3) + bb_width*.2]) - x20;
    height20 = min([height, bb(4) + bb_height*.2]) - y20;
    imageName = ['data/new-set/crop20/' sprintf('%04d', img) '.jpg'];
    imwrite(imcrop(image, [x20, y20, width20, height20]), imageName); 
    img = img + 1;
end