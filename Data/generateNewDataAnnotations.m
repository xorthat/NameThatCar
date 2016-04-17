load('cars_train_annos.mat');
new_bb = csvread('data/new-set/test_boundingboxes.csv');
new_labels = csvread('data/new-set/new_labels_converted.txt');
newDataAnnotations = repmat(annotations(1,1),1,size(new_bb,1));
new_dir = dir('data/new-set');
numImgs = 1;

for i = 1:size(new_dir, 1)
    if and(isempty(strfind(new_dir(i).name, '.jpg')), ...
        isempty(strfind(new_dir(i).name, '.png')))
        continue
    end
    newDataAnnotations(1,imgs).fname = new_dir(i).name;
    newDataAnnotations(1,imgs).bbox_x1 = new_bb(img, 1);
    newDataAnnotations(1,imgs).bbox_y1 = new_bb(img, 2);
    newDataAnnotations(1,imgs).bbox_x2 = new_bb(img, 3);
    newDataAnnotations(1,imgs).bbox_y2 = new_bb(img, 4);
    newDataAnnotations(1,imgs).class = new_labels(img, 1);
    img = img + 1;
end